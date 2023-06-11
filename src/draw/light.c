/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:28:34 by faksouss          #+#    #+#             */
/*   Updated: 2023/06/11 01:13:31 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_rgb	add_clr(t_rgb cl1, t_rgb cl2, double r)
{
	t_vctr	pc;

	pc.x = (double)cl1.r * ((double)cl2.r / 255) * r;
	pc.y = (double)cl1.g * ((double)cl2.g / 255) * r;
	pc.z = (double)cl1.b * ((double)cl2.b / 255) * r;
	return ((t_rgb){(int)pc.x, (int)pc.y, (int)pc.z});
}

t_rgb	get_obj_clr(t_object *obj)
{
	if (obj->type == SPHERE)
		return (((t_sphere *)obj->objct)->clr);
	if (obj->type == PLANE)
		return (((t_plane *)obj->objct)->clr);
	if (obj->type == CYLENDER)
		return (((t_cylender *)obj->objct)->clr);
	return ((t_rgb){0, 0, 0});
}

int	no_hit(t_abt_lt *am)
{
	t_rgb	clr;

	clr.r = (int)(am->clr.r / 255 * am->brightness);
	clr.g = (int)(am->clr.g / 255 * am->brightness);
	clr.b = (int)(am->clr.b / 255 * am->brightness);
	return (encode_rgb(&clr));
}

int	blind(t_ray *r, t_object *obj, t_crd l)
{
	t_object	*tmp;
	t_object	*hld;
	t_ray		tp;
	double		t;
	double		cls;

	cls = DBL_MAX;
	hld = NULL;
	tmp = obj;
	while (tmp)
	{
		if (is_a_hit(tmp->objct, tmp->type, r, &t) && cls - t >= EPS)
		{
			cls = t;
			hld = tmp;
			tp.org = add_vctr(r->org, vctr_scl(r->drct, t));
			tp.drct = get_nrm_att(hld, &tp, r, t);
		}
		tmp = tmp->next;
	}
	if (hld)
		if (vctr_len(sub_vctr(tp.org, r->org)) < vctr_len(sub_vctr(l, r->org)))
			return (1);
	return (0);
}

t_rgb	visible(t_ray *r, t_vctr nrm, t_rgb obj, t_rt *rt)
{
	double	df;
	t_rgb	cl;
	t_rgb	d;

	d = (t_rgb){0, 0, 0};
	df = dot_prdct(r->drct, nrm);
	cl = add_clr(obj, rt->al->clr, rt->al->brightness);
	if (df >= 0)
		d = add_clr(obj, rt->lt->clr, rt->lt->bright * df);
	return ((t_rgb){cl.r + d.r, cl.g + d.g, cl.b + d.b});
}
