/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecrtors_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:31:13 by faksouss          #+#    #+#             */
/*   Updated: 2023/06/10 01:23:44 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_vctr	add_vctr(t_vctr v1, t_vctr v2)
{
	return ((t_vctr){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z});
}

t_vctr	mltp_vctr(t_vctr v1, t_vctr v2)
{
	return ((t_vctr){v1.x * v2.x, v1.y * v2.y, v1.z * v2.z});
}

t_vctr	vctr_scl(t_vctr v, double s)
{
	return ((t_vctr){v.x * s, v.y * s, v.z * s});
}

double	dot_prdct(t_vctr v1, t_vctr v2)
{
	return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

double	vctr_len(t_vctr v)
{
	return (sqrt(dot_prdct(v, v)));
}
