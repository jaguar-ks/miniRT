/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:28:34 by faksouss          #+#    #+#             */
/*   Updated: 2023/06/07 01:23:43 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/minirt.h"

int no_hit(t_abt_lt *am)
{
    t_rgb   clr;

    clr.r = (int)(am->clr.r * am->brightness);
    clr.g = (int)(am->clr.g * am->brightness);
    clr.b = (int)(am->clr.b * am->brightness);
    return (encode_rgb(&clr));
}

int shadow(t_abt_lt *am, t_object *obj)
{
    t_vctr      pc;
    t_rgb       clr;

    if (obj->type == SPHERE)
        clr = ((t_sphere *)obj->objct)->clr;
    else if (obj->type == CYLENDER)
        clr = ((t_cylender *)obj->objct)->clr;
    else if (obj->type == CYLENDER)
        clr = ((t_plane *)obj->objct)->clr;
    pc.x = (double)clr.r * ((double)am->clr.r / 255) * am->brightness;
    pc.y = (double)clr.g * ((double)am->clr.g / 255) * am->brightness;
    pc.z = (double)clr.b * ((double)am->clr.b / 255) * am->brightness;
    clr = (t_rgb){(int)pc.x, (int)pc.y, (int)pc.z};
    return (encode_rgb(&clr));
}

int light_color(t_abt_lt *am, t_light *lg, t_object *obj, t_ray *ray)
{
    t_vctr  nrm;
    t_rgb   clr;
    t_vctr   pc;
    double  df;

    if (obj->type == SPHERE)
        nrm = unit_vctr(sub_vctr(((t_sphere *)obj->objct)->crd, ray->org));
    if (obj->type == PLANE)
    {
        nrm = unit_vctr(((t_plane *)obj->objct)->nrml_vctr);
        if (dot_prdct(nrm, ray->drct) < 0)
            nrm = vctr_scl(nrm, -1);
    }
    if (obj->type == CYLENDER)
        nrm = unit_vctr(sub_vctr(((t_cylender *)obj->objct)->crd, ray->org));
    if (obj->type == SPHERE)
        clr = ((t_sphere *)obj->objct)->clr;
    else if (obj->type == PLANE)
        clr = ((t_plane *)obj->objct)->clr;
    else if (obj->type == CYLENDER)
        clr = ((t_cylender *)obj->objct)->clr;
    df = dot_prdct(ray->drct, nrm);
    // df *= -1;
    pc.x = (double)clr.r * ((double)am->clr.r / 255) * am->brightness;
    pc.y = (double)clr.g * ((double)am->clr.g / 255) * am->brightness;
    pc.x = (double)clr.b * ((double)am->clr.b / 255) * am->brightness;
    if (df > 0)
    {
        pc.x += (double)clr.r * ((double)lg->clr.r / 255) * (lg->bright * df);
        pc.y += (double)clr.g * ((double)lg->clr.g / 255) * (lg->bright * df);
        pc.z += (double)clr.b * ((double)lg->clr.b / 255) * (lg->bright * df);
    }
    clr = (t_rgb){(int)pc.x, (int)pc.y, (int)pc.z};
    return (encode_rgb(&clr));
}
