/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cy_ut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:15:03 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/10 04:48:14 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_cy_rgb(char *rgb_string, t_cylender *cy)
{
	int		r;
	int		g;
	int		b;
	char	**rgb_values;

	r = 0;
	g = 0;
	b = 0;
	rgb_values = ft_split(rgb_string, ',');
	if (rgb_values != NULL && mtx_len(rgb_values) == 3)
	{
		if (ft_strlen(rgb_values[0]) <= 3 && ft_strlen(rgb_values[1]) <= 3
			&& ft_strlen(rgb_values[2]) <= 3)
		{
			r = M_ft_atoi(rgb_values[0]);
			g = M_ft_atoi(rgb_values[1]);
			b = M_ft_atoi(rgb_values[2]);
			if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255)
			{
				cy->clr.r = r;
				cy->clr.g = g;
				cy->clr.b = b;
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
		if (ft_atof(ptr[0]) != 1337 && ft_atof(ptr[1]) != 1337 && ft_atof(ptr[2]) != 1337)
		{
			rt->crd.x = ft_atof(ptr[0]);
			rt->crd.y = ft_atof(ptr[1]);
			rt->crd.z = ft_atof(ptr[2]);
		}
		else
		{
			ft_printf("Error: Invalid light coordinates\n", 1);
			exit(EXIT_FAILURE);
		}
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
		ft_printf("Error: 3d vector. In range[-1,1]x,y,z axis for cy\n", 2);
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
	if (ptr != NULL && mtx_len(ptr) == 3)
		get_vec_cy(ptr, rt);
	else
	{
        ft_printf("Error: allocation comming form : [ft_cy_vec]\n", 2);
	    exit(1);
    }
}
