/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:36:28 by faksouss          #+#    #+#             */
/*   Updated: 2023/06/04 22:58:23 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/minirt.h"

t_vctr  sub_vctr(t_vctr v1, t_vctr v2)
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
	t1 = -abc.y + sqrt(delta) / 2 * abc.x;
	t2 = -abc.y - sqrt(delta) / 2 * abc.x;
    if (t1 - t2 < EPS)
		*t = t1;
	else
		*t = t2;
	return (1);
}

int	check_pln_intersection(t_plane *pl, t_ray *ray, double *t)
{
	double	t1;
    t_vctr  v;

    v = sub_vctr(ray->org, pl->crd);
	t1 = (dot_prdct(sub_vctr(pl->crd, ray->org), pl->nrml_vctr))
		/ dot_prdct(pl->nrml_vctr, ray->drct);
	if (t1 > EPS)
		return (*t = t1, 1);
	return (0);
}

int check_cyl_intersection(t_cylender *cy, t_ray *ray, double *t)
{
    t_vctr  s;
    t_vctr  v;
    double  t1;
    double  t2;
    double  delta;

    cy->nrml_vctr = unit_vctr(cy->nrml_vctr);
    v = sub_vctr(ray->org, cy->crd);
    s.x = dot_prdct(ray->drct, ray->drct) - pow(dot_prdct(ray->drct, cy->nrml_vctr), 2);
    s.y = 2 * (dot_prdct(ray->drct, v) - (dot_prdct(ray->drct, cy->nrml_vctr) * dot_prdct(v, cy->nrml_vctr)));
    s.z = dot_prdct(v, v) - pow(dot_prdct(v, cy->nrml_vctr), 2) - pow(cy->dmt / 2, 2);
    delta = pow(s.y, 2) - 4 * (s.x * s.z);
    if (delta < EPS)
        return (0);
    t1 = -s.y - sqrt(delta) / 2 * s.x;
    t2 = -s.y + sqrt(delta) / 2 * s.x;
    if (t2 < EPS)
        return (0);
    t1 = dot_prdct(ray->drct, cy->nrml_vctr) * t1 + dot_prdct(v, cy->nrml_vctr);
    t1 = dot_prdct(ray->drct, cy->nrml_vctr) * t2 + dot_prdct(v, cy->nrml_vctr);
    if (t2 >= EPS && t2 <= cy->hgt)
        return (*t = (-s.y + sqrt(delta)) / (2 * s.x), 1);
    if (t1 >= EPS && t1 <= cy->hgt)
        return (*t = (-s.y - sqrt(delta)) / (2 * s.x), 1);
    return (0);
}
