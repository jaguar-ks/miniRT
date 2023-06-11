/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_al_ut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 01:57:19 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/11 02:05:44 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static int	valid_rgb(char **rgb_values, int *r, int *g, int *b)
{
	if (ft_strlen(rgb_values[0]) <= 3 && ft_strlen(rgb_values[1]) <= 3
		&& ft_strlen(rgb_values[2]) <= 3)
	{
		*r = m_ft_atoi(rgb_values[0]);
		*g = m_ft_atoi(rgb_values[1]);
		*b = m_ft_atoi(rgb_values[2]);
		if (*r >= 0 && *r <= 255 && *g >= 0 && *g <= 255 && *b >= 0
			&& *b <= 255)
			return (1);
		else
			ft_exit("Error: In light's values of RGB\n", 1);
	}
	else
		ft_exit("Error: Problem with the RGB len\n", 1);
	return (0);
}

static void	assign_rgb(t_rt *rt, int r, int g, int b)
{
	rt->al->clr.r = r;
	rt->al->clr.g = g;
	rt->al->clr.b = b;
}

void	ft_rgb_al(char *string, t_rt *rt)
{
	char	**ptr;
	int		r;
	int		g;
	int		b;

	ptr = ft_split(string, ',');
	if (ptr != NULL && mtx_len(ptr) == 3)
	{
		if (valid_rgb(ptr, &r, &g, &b))
			assign_rgb(rt, r, g, b);
		else
			ft_exit("Error: Problem with the RGB len\n", 1);
		deallocate(ptr);
	}
	else
		ft_exit("Error: RGB input problem in camera\n", 1);
}
