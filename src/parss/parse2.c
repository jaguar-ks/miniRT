/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:16:05 by nbouljih          #+#    #+#             */
/*   Updated: 2023/05/30 12:27:32 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void    parse_obj(t_rt *rt)
{
    t_count x;

    x.cy = 0;
    x.pl = 0;
    x.ps = 0;
    len_elem(rt->fl, &x.pl, &x.ps, &x.cy);
    rt->object = NULL;
    ft_pl(rt, x.pl);
    ft_sp(rt, x.ps);
    ft_cy(rt, x.cy);
}
