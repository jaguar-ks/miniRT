/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_ut.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:34:45 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/09 20:56:06 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_pl_Cordination(char *string, t_plane *rt)
{
	char	**ptr;

	ptr = ft_split(string, ',');
	if (ptr != NULL && mtx_len(ptr) == 3)
	{
		rt->crd.x = ft_atof(ptr[0]);
		rt->crd.y = ft_atof(ptr[1]);
		rt->crd.z = ft_atof(ptr[2]);
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
	if (ft_atof(ptr[0]) > 1.0 || ft_atof(ptr[0]) < -1.0 || ft_atof(ptr[1]) > 1.0
		|| ft_atof(ptr[1]) < -1.0 || ft_atof(ptr[2]) > 1.0 || ft_atof(ptr[2]) <
		-1.0)
	{
		ft_printf("Error: 3d normalized normal vector. In range [-1,1] for each x,y,z axis for pl\n",
			2);
		exit(EXIT_FAILURE);
	}
	else
	{
		rt->nrm.x = ft_atof(ptr[0]);
		rt->nrm.y = ft_atof(ptr[1]);
		rt->nrm.z = ft_atof(ptr[2]);
	}
}
void	ft_pl_vec(char *string, t_plane *rt)
{
	char	**ptr;

	ptr = ft_split(string, ',');
	if (!ptr && mtx_len(ptr) != 3)
	{
		ft_printf("Error: allocation comming form : [ft_pl_vec]\n", 2);
		exit(1);
	}
	else
		get_vec(ptr, rt);
}
