/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cy_ut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:15:03 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/10 23:04:57 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_cy_cord(char *string, t_cylender *rt)
{
	char	**ptr;

	ptr = ft_split(string, ',');
	if (ptr != NULL && mtx_len(ptr) == 3)
	{
		if (ft_atof(ptr[0]) != 1337 && ft_atof(ptr[1]) != 1337
			&& ft_atof(ptr[2]) != 1337)
		{
			rt->crd.x = ft_atof(ptr[0]);
			rt->crd.y = ft_atof(ptr[1]);
			rt->crd.z = ft_atof(ptr[2]);
		}
		else
			ft_exit("Error: Invalid light coordinates\n", 1);
		deallocate(ptr);
	}
	else
		ft_exit("Error: Invalid light coordinates\n", 1);
}

void	check_vector_range(char **ptr, t_cylender *rt)
{
	float	x;
	float	y;
	float	z;

	x = ft_atof(ptr[0]);
	y = ft_atof(ptr[1]);
	z = ft_atof(ptr[2]);
	if (x > 1.0 || x < -1.0)
		ft_exit("Error: Invalid x-axis value for cylinder\n", 2);
	if (y > 1.0 || y < -1.0)
		ft_exit("Error: Invalid y-axis value for cylinder\n", 2);
	if (z > 1.0 || z < -1.0)
		ft_exit("Error: Invalid z-axis value for cylinder\n", 2);
	rt->nrm.x = x;
	rt->nrm.y = y;
	rt->nrm.z = z;
}

void	get_vec_cy(char **ptr, t_cylender *rt)
{
	check_vector_range(ptr, rt);
	deallocate(ptr);
}

void	ft_cy_vec(char *string, t_cylender *rt)
{
	char	**ptr;

	ptr = ft_split(string, ',');
	if (ptr != NULL && mtx_len(ptr) == 3)
		get_vec_cy(ptr, rt);
	else
	{
		ft_printf("Error: allocation comming form : [ft_cy_vec]\n", 2);
		exit(1);
	}
}
