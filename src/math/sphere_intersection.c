/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:36:28 by faksouss          #+#    #+#             */
/*   Updated: 2023/06/01 12:23:43 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/minirt.h"

int check_sph_intersection(t_sphere *sp, t_ray *ray, double *t)
{
    double  a;
    double  b;
    double  c;
    double  t1;
    double  t2;
    double  delta;

    a = dot_prdct(ray->drct, ray->drct);
    b = 2 * (ray->drct.x * sp->crd.x + ray->drct.y * sp->crd.y + ray->drct.z * sp->crd.z);
    c = dot_prdct(sp->crd, sp->crd) - pow(sp->dmt / 2, 2);
    delta = pow(b, 2) - 4 * (a * c);
    // printf("DELTA = %f\n", delta);
    if (delta < 0)
        return (0);
    t1 = -b + sqrt(delta) / 2 * a;
    t2 = -b - sqrt(delta) / 2 * a;
    // printf("solutions = %f | %f\n", t1, t2);
    if (t1 < t2)
        *t = t1;
    else
        *t = t2;
    return (1);
}

// int check_pln_intersection(t_plane *sp, t_ray *ray, double *t)
// {
    
// }
