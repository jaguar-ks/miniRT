/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_rayes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:43:00 by faksouss          #+#    #+#             */
/*   Updated: 2023/05/29 10:19:44 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/minirt.h"

t_ray   make_ray(t_scn *scn, double x, double y)
{
    t_ray   ray;

    ray.org = scn->pst;
    ray.drct = add_vctr(add_vctr(vctr_scl(scn->rght, x), vctr_scl(scn->up, y)),
        scn->frwrd);
    ray.drct = unit_vctr(ray.drct);
    return (ray);
}

int is_a_hit(void *obj, ObjectType type, t_ray *ray, double *t)
{
    if (type == SPHERE)
        return (check_sph_intersection((t_sphere *)obj, ray, t));
    return (0);
}

int pix_color(void *hold, ObjectType type)
{
    t_sphere    *sp = (t_sphere *)hold;
    if (type == SPHERE)
        return (encode_rgb(&sp->clr));
    return (0);
}

int    find_pix_color(t_rt *rt, t_ray *ray)
{
    double      cls;
    double      t;
    t_object    *obj;
    t_object    *hold;

    hold = NULL;
    obj = rt->object;
    cls = DBL_MAX;
    while (obj)
    {
        if (is_a_hit(obj->objct, obj->type, ray, &t) && less_then(&cls, t))
            hold = obj;
        obj = obj->next;
    }
    if (hold)
        return (pix_color(hold->objct, hold->type));
    else
        return (encode_rgb(&rt->al->clr));
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
            x = (double)i * scn->hg;
            y = (double)j * scn->wg;
            ray = make_ray(scn, x, y);
            img_pix_put(rt->mlx->img, i, j, find_pix_color(rt, &ray));
        }
    }
}
