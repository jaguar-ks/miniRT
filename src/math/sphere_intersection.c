/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:36:28 by faksouss          #+#    #+#             */
/*   Updated: 2023/06/02 20:50:59 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/minirt.h"

int	check_sph_intersection(t_sphere *sp, t_ray *ray, double *t)
{
	t_vctr	abc;
	double	t1;
	double	t2;
	double	delta;

	abc.x = dot_prdct(ray->drct, ray->drct);
	abc.y = 2 * (ray->drct.x * sp->crd.x + ray->drct.y * sp->crd.y + ray->drct.z
			* sp->crd.z);
	abc.z = dot_prdct(sp->crd, sp->crd) - pow(sp->dmt / 2, 2);
	delta = pow(abc.y, 2) - 4 * (abc.y * abc.z);
	if (delta < 0)
		return (0);
	t1 = -abc.y + sqrt(delta) / 2 * abc.x;
	t2 = -abc.y - sqrt(delta) / 2 * abc.x;
	if (t1 < t2)
		*t = t1;
	else
		*t = t2;
	return (1);
}

int	check_pln_intersection(t_plane *pl, t_ray *ray, double *t)
{
	double	t1;

	t1 = (dot_prdct(pl->nrml_vctr, pl->crd)
			- dot_prdct(pl->nrml_vctr, ray->org))
		/ dot_prdct(pl->nrml_vctr, ray->drct);
	if (t1 > EPS)
		return (*t = t1, 1);
	return (0);
}
