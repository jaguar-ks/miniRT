/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cy_ut2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 22:56:38 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/11 01:19:38 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	parse_rgb_values(char **rgb_values, t_cylender *cy)
{
	int	r;
	int	g;
	int	b;

	r = 0;
	g = 0;
	b = 0;
	if (ft_strlen(rgb_values[0]) <= 3 && ft_strlen(rgb_values[1]) <= 3
		&& ft_strlen(rgb_values[2]) <= 3)
	{
		r = m_ft_atoi(rgb_values[0]);
		g = m_ft_atoi(rgb_values[1]);
		b = m_ft_atoi(rgb_values[2]);
		if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255)
		{
			cy->clr.r = r;
			cy->clr.g = g;
			cy->clr.b = b;
		}
		else
			ft_exit("Error: Invalid RGB values in cylinder\n", 2);
	}
	else
		ft_exit("Error: Problem with the RGB length\n", 2);
}

void	ft_cy_rgb(char *rgb_string, t_cylender *cy)
{
	char	**rgb_values;

	rgb_values = ft_split(rgb_string, ',');
	if (rgb_values != NULL && mtx_len(rgb_values) == 3)
	{
		parse_rgb_values(rgb_values, cy);
		deallocate(rgb_values);
	}
	else
		ft_exit("Error: RGB problem in cylinder\n", 2);
}
