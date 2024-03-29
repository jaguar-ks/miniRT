/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_ut.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:34:45 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/10 05:40:05 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_pl_cordination(char *string, t_plane *rt)
{
	char	**ptr;

	ptr = ft_split(string, ',');
	if (ptr != NULL && mtx_len(ptr) == 3)
	{
		if (ft_atof(ptr[0]) == 1337 || ft_atof(ptr[1]) == 1337
			|| ft_atof(ptr[2]) == 1337)
		{
			exit(1);
		}
		else
		{
			rt->crd.x = ft_atof(ptr[0]);
			rt->crd.y = ft_atof(ptr[1]);
			rt->crd.z = ft_atof(ptr[2]);
		}
		deallocate(ptr);
	}
	else
	{
		ft_printf("Error: Invalid light coordinates\n", 1);
		exit(EXIT_FAILURE);
	}
}

void	get_vec(char **ptr, t_plane *rt)
{
	if (ft_atof(ptr[0]) > 1.0 || ft_atof(ptr[0]) < -1.0
		|| ft_atof(ptr[1]) > 1.0 || ft_atof(ptr[1]) < -1.0
		|| ft_atof(ptr[2]) > 1.0 || ft_atof(ptr[2]) < -1.0)
	{
		ft_printf("Error: 3dvector.In range [-1,1]for each x,y,z(pl)\n", 2);
		exit(EXIT_FAILURE);
	}
	else
	{
		rt->nrm.x = ft_atof(ptr[0]);
		rt->nrm.y = ft_atof(ptr[1]);
		rt->nrm.z = ft_atof(ptr[2]);
	}
	deallocate(ptr);
}

void	ft_pl_vec(char *string, t_plane *rt)
{
	char	**ptr;

	ptr = ft_split(string, ',');
	if (ptr != NULL && mtx_len(ptr) == 3)
		get_vec(ptr, rt);
	else
	{
		ft_printf("Error: allocation comming form : [ft_pl_vec]\n", 2);
		exit(1);
	}
}
