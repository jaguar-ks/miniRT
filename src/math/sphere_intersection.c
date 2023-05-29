/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:36:28 by faksouss          #+#    #+#             */
/*   Updated: 2023/05/29 10:11:52 by faksouss         ###   ########.fr       */
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
    b = 2 * dot_prdct(sp->crd, ray->drct);
    c = dot_prdct(sp->crd, sp->crd) - pow(sp->dmt / 2, 2);
    delta = pow(b, 2) - 4 * (a * c);
    if (delta < EPS)
        return (printf("is not a hit"), 0);
    t1 = -b + sqrt(delta) / 2 * a;
    t2 = -b - sqrt(delta) / 2 * a;
    if (t1 < t2)
        *t = t1;
    else
        *t = t2;
    printf("is a hit");
    return (1);
}
