/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:36:28 by faksouss          #+#    #+#             */
/*   Updated: 2023/06/11 01:22:43 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_vctr	sub_vctr(t_vctr v1, t_vctr v2)
{
	return ((t_vctr){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z});
}

int	check_sph_intersection(t_sphere *sp, t_ray *ray, double *t)
{
	t_vctr	abc;
	t_vctr	v;
	double	t1;
	double	t2;
	double	delta;

	v = sub_vctr(ray->org, sp->crd);
	abc.x = dot_prdct(ray->drct, ray->drct);
	abc.y = 2 * dot_prdct(v, ray->drct);
	abc.z = dot_prdct(v, v) - pow(sp->dmt / 2, 2);
	delta = pow(abc.y, 2) - 4 * abc.x * abc.z;
	if (delta < EPS)
		return (0);
	t1 = (-abc.y + sqrt(delta)) / (2 * abc.x);
	t2 = (-abc.y - sqrt(delta)) / (2 * abc.x);
	if (t1 < EPS)
		return (0);
	if (t1 < t2)
		*t = t1;
	else
		*t = t2;
	return (1);
}

int	check_pln_intersection(t_plane *pl, t_ray *ray, double *t)
{
	double	t1;
	double	b;
	t_vctr	v;

	v = sub_vctr(ray->org, pl->crd);
	b = dot_prdct(ray->drct, unit_vctr(pl->nrm));
	if (b != 0)
	{
		t1 = (dot_prdct(unit_vctr(pl->nrm), v) * -1) / b;
		if (t1 >= EPS)
			return (*t = t1, 1);
		return (0);
	}
	return (0);
}

int	check_cyl_intersection(t_cylender *cy, t_ray *ray, double *t)
{
	t_vctr	s;
	t_vctr	v;
	t_vctr	d;

	cy->nrm = unit_vctr(cy->nrm);
	v = sub_vctr(ray->org, cy->crd);
	s.x = dot_prdct(ray->drct, ray->drct) - pow(dot_prdct(ray->drct, cy->nrm),
			2);
	s.y = 2 * (dot_prdct(ray->drct, v) - (dot_prdct(ray->drct, cy->nrm)
				* dot_prdct(v, cy->nrm)));
	s.z = dot_prdct(v, v) - pow(dot_prdct(v, cy->nrm), 2) - pow(cy->dmt / 2, 2);
	d.x = pow(s.y, 2) - (4 * s.x * s.z);
	if (d.x < EPS)
		return (0);
	d.y = (-s.y - sqrt(d.x)) / (2 * s.x);
	d.z = (-s.y + sqrt(d.x)) / (2 * s.x);
	if (d.z < EPS)
		return (0);
	d.y = dot_prdct(ray->drct, cy->nrm) * d.y + dot_prdct(v, cy->nrm);
	d.z = dot_prdct(ray->drct, cy->nrm) * d.z + dot_prdct(v, cy->nrm);
	if (d.y > EPS && d.y < cy->hgt)
		return (*t = (-s.y - sqrt(d.x)) / (2 * s.x), 1);
	else if (d.z > EPS && d.z < cy->hgt)
		return (*t = (-s.y + sqrt(d.x)) / (2 * s.x), 1);
	return (0);
}

t_vctr	get_nrm_att(t_object *obj, t_ray *r, t_ray *p, double t)
{
	t_vctr	nrm;
	t_vctr	oc;
	double	s;

	if (obj->type == SPHERE)
		nrm = unit_vctr(sub_vctr(r->org, ((t_sphere *)obj->objct)->crd));
	if (obj->type == PLANE)
	{
		nrm = unit_vctr(((t_plane *)obj->objct)->nrm);
		if (dot_prdct(nrm, p->drct) >= EPS)
			nrm = vctr_scl(nrm, -1);
	}
	if (obj->type == CYLENDER)
	{
		oc = unit_vctr(((t_cylender *)obj->objct)->nrm);
		s = dot_prdct(p->drct, vctr_scl(oc, t)) + dot_prdct(sub_vctr(p->org,
					((t_cylender *)obj->objct)->crd), oc);
		nrm = unit_vctr(sub_vctr(sub_vctr(r->org,
						((t_cylender *)obj->objct)->crd), vctr_scl(oc, s)));
	}
	return (nrm);
}
