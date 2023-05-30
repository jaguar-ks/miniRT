/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecrtors_operations_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:36:56 by faksouss          #+#    #+#             */
/*   Updated: 2023/05/30 12:41:45 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/minirt.h"
#include<stdbool.h>

t_vctr  unit_vctr(t_vctr v)
{
    double len = vctr_len(v);
    return ((t_vctr){v.x / len, v.y / len, v.z / len});
}

t_vctr  cros_prdct(t_vctr v1, t_vctr v2)
{
    return ((t_vctr){(v1.y * v2.z - v1.z * v2.y),
        (v1.z * v2.x - v1.x * v2.z), (v1.x * v2.y - v1.y * v2.x)});
}

double  dgr_to_rd(double  angle)
{
    return (angle * M_PI / 180);
}

bool    double_equality(double a, double b) {
    if(fabs(a - b) < EPS)
        return (TRUE);
    else
        return (FALS);
}
