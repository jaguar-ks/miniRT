/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_rayes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:43:00 by faksouss          #+#    #+#             */
/*   Updated: 2023/06/06 00:34:44 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	is_a_hit(void *obj, t_ObjectType type, t_ray *ray, double *t)
{
	if (type == SPHERE)
		return (check_sph_intersection((t_sphere *)obj, ray, t));
	if (type == PLANE)
		return (check_pln_intersection((t_plane *)obj, ray, t));
	if (type == CYLENDER)
		return (check_cyl_intersection((t_cylender *)obj, ray, t));
	return (0);
}

int	pix_color(t_rt *rt, t_object *obj, t_ray *ray, double t)
{
	t_ray		r;
	t_object	*tmp;
	double		t;

	r.org = add_vctr(ray->org, vctr_scl(ray->drct, t));
	r.drct = sub_vctr(r.org, rt->lt->crd);
	tmp = rt->object;
	while (tmp)
	{
		if (is_a_hit(tmp->objct, tmp->type, &r, &t) && t)
			return (); // shadow
		tmp = tmp->next;
	}
	return (); // light
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
	while (obj != NULL)
	{
		if (is_a_hit(obj->objct, obj->type, ray, &t) && (cls > t))
		{
			cls = t;
			hold = obj;
		}
		obj = obj->next;
	}
	return (pix_color(rt, hold, ray, t));
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
	while (--i > 0)
	{
		j = WIGHT;
		while (--j > 0)
		{
			x = (((double)i) * 2) / HIGHT - 1;
			y = (((double)j) * 2) / WIGHT - 1;
			ray.drct = add_vctr(add_vctr(vctr_scl(scn->rght, -x * scn->hg),
					vctr_scl(scn->up, y * scn->wg)), scn->frwrd);
			ray.drct = unit_vctr(ray.drct);
			img_pix_put(rt->mlx->img, i, j, find_pix_color(rt, &ray));
		}
	}
}
