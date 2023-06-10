/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cy_ut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:15:03 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/10 01:13:34 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_cy_rgb(char *rgb_string, t_cylender *cy)
{
	int		R;
	int		G;
	int		B;
	char	**rgb_values;

	R = 0;
	G = 0;
	B = 0;
	rgb_values = ft_split(rgb_string, ','); // Split the RGB values
	if (rgb_values != NULL && mtx_len(rgb_values) == 3)
	{
		if (ft_strlen(rgb_values[0]) <= 3 && ft_strlen(rgb_values[1]) <= 3
			&& ft_strlen(rgb_values[2]) <= 3)
		{
			R = M_ft_atoi(rgb_values[0]);
			G = M_ft_atoi(rgb_values[1]);
			B = M_ft_atoi(rgb_values[2]);
			if (R >= 0 && R <= 255 && G >= 0 && G <= 255 && B >= 0 && B <= 255)
			{
				cy->clr.r = R;
				cy->clr.g = G;
				cy->clr.b = B;
			}
			else
			{
				ft_printf("Error: Invalid RGB values in cyender\n", 2);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			ft_printf("Error: Problem with the RGB length\n", 2);
			exit(EXIT_FAILURE);
		}
		deallocate(rgb_values);
	}
	else
	{
		ft_printf("Error: RGB problem in camera\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	ft_cy_cord(char *string, t_cylender *rt)
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

void	get_vec_cy(char **ptr, t_cylender *rt)
{
	if (ft_atof(ptr[0]) > 1.0 || ft_atof(ptr[0]) < -1.0 || ft_atof(ptr[1]) > 1.0
		|| ft_atof(ptr[1]) < -1.0 || ft_atof(ptr[2]) > 1.0 || ft_atof(ptr[2]) <
		-1.0)
	{
		ft_printf("Error: 3d normalized normal vector. In range [-1,1] for each x,y,z axis for cy\n",
			2);
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
void	ft_cy_vec(char *string, t_cylender *rt)
{
	char	**ptr;

	ptr = ft_split(string, ',');
	if (!ptr && mtx_len(ptr) != 3)
	{
		ft_printf("Error: allocation comming form : [ft_cy_vec]\n", 2);
		exit(1);
	}
	else
		get_vec_cy(ptr, rt);
}
