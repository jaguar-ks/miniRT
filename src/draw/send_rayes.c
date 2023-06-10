/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_rayes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:43:00 by faksouss          #+#    #+#             */
/*   Updated: 2023/06/10 01:52:19 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	is_a_hit(void *obj, t_ObjectType type, t_ray *ray, double *t)
{
	t_plane	*pl;

	if (type == PLANE)
	{
		pl = (t_plane *)obj;
		pl->nrm = vctr_scl(pl->nrm, -1);
		return (check_pln_intersection((t_plane *)obj, ray, t)
			|| check_pln_intersection(pl, ray, t));
		return (check_pln_intersection((t_plane *)obj, ray, t));
	}
	else if (type == SPHERE)
		return (check_sph_intersection((t_sphere *)obj, ray, t));
	else if (type == CYLENDER)
		return (check_cyl_intersection((t_cylender *)obj, ray, t));
	return (0);
}

int	pix_color(t_rt *rt, t_object *obj, t_ray *ray, double t)
{
	t_hit_point	hp;

	hp.r.org = add_vctr(ray->org, vctr_scl(ray->drct, t));
	hp.nrm = get_nrm_att(obj, &hp.r, ray, t);
	if (dot_prdct(hp.nrm, ray->drct) >= EPS)
		hp.nrm = vctr_scl(hp.nrm, -1);
	hp.r.drct = unit_vctr(sub_vctr(rt->lt->crd, hp.r.org));
	if (blind(&hp.r, rt->object, rt->lt->crd))
		hp.px_cl = add_clr(get_obj_clr(obj), rt->al->clr, rt->al->brightness);
	else
		hp.px_cl = visible(&hp.r, hp.nrm, get_obj_clr(obj), rt);
	return (encode_rgb(&hp.px_cl));
}

int	find_pix_color(t_rt *rt, t_ray *ray)
{
	double		cls;
	double		t;
	t_object	*obj;
	t_object	*hold;

	hold = NULL;
	obj = rt->object;
	cls = DBL_MAX;
	while (obj)
	{
		if (is_a_hit(obj->objct, obj->type, ray, &t) && t > EPS && cls
			- t > EPS)
		{
			cls = t;
			hold = obj;
		}
		obj = obj->next;
	}
	if (hold)
		return (pix_color(rt, hold, ray, cls));
	return (0);
}

void	send_rays(t_rt *rt, t_scn *scn)
{
	int		i;
	int		j;
	double	x;
	double	y;
	t_ray	ray;

	i = HIGHT;
	ray.org = scn->pst;
	while (--i >= 0)
	{
		j = WIGHT;
		while (--j >= 0)
		{
			x = (((double)i) * 2) / HIGHT - 1;
			y = (((double)j) * 2) / WIGHT - 1;
			ray.drct = add_vctr(scn->frwrd, add_vctr(vctr_scl(scn->up, y
							* scn->wg), vctr_scl(scn->rght, -x * scn->hg)));
			ray.drct = unit_vctr(ray.drct);
			img_pix_put(rt->mlx->img, i, j, find_pix_color(rt, &ray));
		}
	}
}
