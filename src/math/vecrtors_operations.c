/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecrtors_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:31:13 by faksouss          #+#    #+#             */
/*   Updated: 2023/05/31 10:25:00 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/minirt.h"

t_vctr  add_vctr(t_vctr v1, t_vctr v2)
{
    return ((t_vctr){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z});
}

t_vctr  mltp_vctr(t_vctr v1, t_vctr v2)
{
    return ((t_vctr){v1.x * v2.x, v1.y * v2.y, v1.z * v2.z});
}

t_vctr  vctr_scl(t_vctr v, double s)
{
    return ((t_vctr){v.x * s, v.y * s, v.z * s});
}

double  dot_prdct(t_vctr v1, t_vctr v2)
{
    return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

double  vctr_len(t_vctr v)
{
    return (sqrt(dot_prdct(v, v)));
}
