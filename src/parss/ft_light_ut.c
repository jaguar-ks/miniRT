/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light_ut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:12:59 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/10 19:20:35 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

// void	ft_light_cordcheck(char **ptr, t_rt *rt)
// {
// 	if (ptr != NULL && mtx_len(ptr) == 3)
// 	{
// 		if ((rt->lt->crd.x = ft_atof(ptr[0])) == 1337
// 			|| (rt->lt->crd.y = ft_atof(ptr[1])) == 1337
// 			|| (rt->lt->crd.z = ft_atof(ptr[2])) == 1337)
// 			ft_exit("Error : atof\n", 2);
// 	}
// }
void	ft_light_cordcheck(char **ptr, t_rt *rt)
{
	float	x;
	float	y;
	float	z;

	if (ptr != NULL && mtx_len(ptr) == 3)
	{
		x = ft_atof(ptr[0]);
		y = ft_atof(ptr[1]);
		z = ft_atof(ptr[2]);
		if (x == 1337 || y == 1337 || z == 1337)
		{
			ft_exit("Error: atof\n", 2);
		}
		rt->lt->crd.x = x;
		rt->lt->crd.y = y;
		rt->lt->crd.z = z;
	}
}

void	ft_light_coordination(char *string, t_rt *rt)
{
	char	**ptr;

	ptr = ft_split(string, ',');
	if (ptr != NULL && mtx_len(ptr) == 3)
	{
		ft_light_cordcheck(ptr, rt);
		rt->lt->crd.x = ft_atof(ptr[0]);
		rt->lt->crd.y = ft_atof(ptr[1]);
		rt->lt->crd.z = ft_atof(ptr[2]);
		deallocate(ptr);
	}
	else
		ft_exit("Error: Invalid light coordinates\n", 1);
}
