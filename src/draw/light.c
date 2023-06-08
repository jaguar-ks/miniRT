/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:28:34 by faksouss          #+#    #+#             */
/*   Updated: 2023/06/08 05:33:24 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/minirt.h"

int no_hit(t_abt_lt *am)
{
    t_rgb   clr;

    clr.r = (int)(am->clr.r / 255 * am->brightness);
    clr.g = (int)(am->clr.g / 255 * am->brightness);
    clr.b = (int)(am->clr.b / 255 * am->brightness);
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

// int light_color(t_abt_lt *am, t_light *lg, t_object *obj, t_ray *ray, t_ray *r)
// {
//     t_vctr  nrm;
//     t_rgb   clr;
//     t_vctr   pc;
//     double  df;

//     // (void)r;
//     pc = (t_vctr){0, 0, 0};
//     if (obj->type == SPHERE)
//         nrm = unit_vctr(sub_vctr(ray->org, ((t_sphere *)obj->objct)->crd));
//     if (obj->type == PLANE)
//     {
//         nrm = unit_vctr(((t_plane *)obj->objct)->nrml_vctr);
//         // if (dot_prdct(nrm, ray->drct) < 0)
//         //     nrm = vctr_scl(nrm, -1);
//     }
//     if (obj->type == CYLENDER)
//         nrm = unit_vctr(cros_prdct(sub_vctr(((t_cylender *)obj->objct)->crd, ray->org), ((t_cylender *)obj->objct)->nrml_vctr));
//     if (dot_prdct(r->drct, nrm) < 0)
//         nrm = vctr_scl(nrm, -1);
//     if (obj->type == SPHERE)
//         clr = ((t_sphere *)obj->objct)->clr;
//     else if (obj->type == PLANE)
//         clr = ((t_plane *)obj->objct)->clr;
//     else if (obj->type == CYLENDER)
//         clr = ((t_cylender *)obj->objct)->clr;
//     df = dot_prdct(ray->drct, nrm);
//     // df *= -1;
//     if (df >= 0)
//     {
//         pc.x = (double)clr.r * ((double)lg->clr.r / 255) * (lg->bright * df);
//         pc.y = (double)clr.g * ((double)lg->clr.g / 255) * (lg->bright * df);
//         pc.z = (double)clr.b * ((double)lg->clr.b / 255) * (lg->bright * df);
//     }
    
//     clr = (t_rgb){(int)pc.x, (int)pc.y, (int)pc.z};
//     return (encode_rgb(&clr));
// }

int blind(t_ray *r, t_object *obj, t_crd l)
{
    t_object    *tmp;
    t_object    *hld;
    double      t;
    double      cls;

    cls = DBL_MAX;
    hld = NULL;
    tmp = obj;
    while (tmp)
    {
        if (is_a_hit(tmp->objct, tmp->type, r, &t) && cls - t > EPS)
        {
            cls = t;
            hld = tmp;
        }
        tmp = tmp->next;
    }
    // if(hld && (hld->type == PLANE))
    //     return(0);
    if (hld && t > EPS && (vctr_len(add_vctr(r->org, vctr_scl(r->drct, t))) < vctr_len(sub_vctr(l, r->org))))
        return (1);
    return (0);
}

t_rgb   visible(t_ray *r, t_vctr nrm, t_rgb obj, t_rt *rt)
{
    double  df;
    t_rgb   cl;
    t_rgb   d;

    d = (t_rgb){0, 0, 0};
    df = dot_prdct(r->drct, nrm);
    cl = add_clr(obj, rt->al->clr, rt->al->brightness);
    if (df >= 0)
        d = add_clr(obj, rt->lt->clr, rt->lt->bright * df);
    return ((t_rgb){cl.r + d.r, cl.g + d.g, cl.b + d.b});
}
