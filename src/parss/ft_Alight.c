/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Alight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:56:33 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/11 02:03:40 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

// void	ft_rgb_al(char *string, t_rt *rt)
// {
// 	int		R;
// 	int		G;
// 	int		B;
// 	char	**ptr;

// 	R = 0;
// 	G = 0;
// 	B = 0;
// 	ptr = ft_split(string, ',');
// 	if (ptr != NULL && mtx_len(ptr) == 3)
// 	{
// 		if (ft_strlen(ptr[0]) <= 3 && ft_strlen(ptr[1]) <= 3
// 			&& ft_strlen(ptr[2]) <= 3)
// 		{
// 			R = m_ft_atoi(ptr[0]);
// 			G = m_ft_atoi(ptr[1]);
// 			B = m_ft_atoi(ptr[2]);
// 			if (R >= 0 && R <= 255 && (G >= 0 && G <= 255) && (B >= 0
// 					&& B <= 255))
// 			{
// 				rt->al->clr.r = R;
// 				rt->al->clr.g = G;
// 				rt->al->clr.b = B;
// 			}
// 			else
// 			{
// 				ft_printf("Error: In cam's values of RGB\n", 1);
// 				exit(EXIT_FAILURE);
// 			}
// 		}
// 		else
// 		{
// 			ft_printf("Error: Problem with the RGB len\n", 1);
// 			exit(EXIT_FAILURE);
// 		}
// 		deallocate(ptr);
// 	}
// 	else
// 	{
// 		ft_printf("Error: RGB input problem in camera\n", 1);
// 		exit(EXIT_FAILURE);
// 	}
// }

void	ft_alight(char *line, t_rt *rt)
{
	double	ratio;
	char	**ptr;

	rt->al = malloc(sizeof(t_abt_lt));
	if (rt->al == NULL)
		ft_exit("Error: Failed to allocate memory for ambient light\n", 1);
	if (rt->al != NULL)
	{
		ptr = ft_split2(line);
		if (mtx_len(ptr) != 3)
			return (deallocate(ptr), ft_printf("Error : A\n", 2), exit(1));
		ratio = ft_atof(ptr[1]);
		if (ratio < 0.0 || ratio > 1.0)
			ft_exit("Error: AL's Ratio range should be btw [0.0,1.0]\n", 2);
		rt->al->brightness = ratio;
		if (rt->al->brightness == 1337)
			ft_exit("Error: ratio in AL\n", 1);
		ft_rgb_al(ptr[2], rt);
		deallocate(ptr);
	}
	else
		ft_exit("Error: Failed to allocate memory for ambient light\n", 1);
}
