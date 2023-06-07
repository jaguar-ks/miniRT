/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_rayes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:43:00 by faksouss          #+#    #+#             */
/*   Updated: 2023/06/07 02:33:00 by faksouss         ###   ########.fr       */
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
	t_object	*hold;
	double		t1;
	double		cls;

    hold = NULL;
    cls = DBL_MAX;
	r.org = add_vctr(ray->org, vctr_scl(ray->drct, t));
	r.drct = unit_vctr(sub_vctr(r.org, rt->lt->crd));
	tmp = rt->object;
    if (!obj)
        return(no_hit(rt->al)); // the ray in this case didn't hit anything
	while (tmp)
	{
		if (is_a_hit(tmp->objct, tmp->type, &r, &t1) && (cls > t1) && (t1 > EPS))
		{
			cls = t1;
			hold = obj;
		}
		tmp = tmp->next;
	}
    if (hold)
		return (shadow(rt->al, obj)); // shadow
	return (light_color(rt->al, rt->lt, obj, &r)); // light
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
    if (hold)
    	return (pix_color(rt, hold, ray, t));
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
