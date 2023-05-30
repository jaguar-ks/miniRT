/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_rayes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:43:00 by faksouss          #+#    #+#             */
/*   Updated: 2023/05/30 14:00:17 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/minirt.h"

t_ray   make_ray(t_scn *scn, double x, double y)
{
    t_ray   ray;

    ray.org = scn->pst;
    ray.drct = add_vctr(add_vctr(vctr_scl(scn->rght, x * scn->hg),
            vctr_scl(scn->up, y * scn->wg)), scn->frwrd);
    ray.drct = unit_vctr(ray.drct);
    return (ray);
}

void    send_rayes(t_rt *rt, t_scn *scn)
{
    int     i;
    int     j;
    double  x;
    double  y;
    t_ray   ray;

    i  = -1;
    while (++i < HIGHT)
    {
        j = -1;
        while (++j < WIGHT)
        {
            x = (double)i * 2 / HIGHT - 1;
            y = (double)j * 2 / WIGHT - 1;
            ray = make_ray(scn, x, y);
        }
    }
}
