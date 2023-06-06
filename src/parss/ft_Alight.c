/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Alight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:56:33 by nbouljih          #+#    #+#             */
/*   Updated: 2023/05/31 10:25:00 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_rgb_al(char *string, t_rt *rt)
{
	int		R;
	int		G;
	int		B;
	char	**ptr;

	R = 0;
	G = 0;
	B = 0;
	ptr = ft_split(string, ',');
	if (ptr != NULL && mtx_len(ptr) == 3)
	{
		if (ft_strlen(ptr[0]) <= 3 && ft_strlen(ptr[1]) <= 3
			&& ft_strlen(ptr[2]) <= 3)
		{
			R = M_ft_atoi(ptr[0]);
			G = M_ft_atoi(ptr[1]);
			B = M_ft_atoi(ptr[2]);
			if (R >= 0 && R <= 255 && (G >= 0 && G <= 255) && (B >= 0
					&& B <= 255))
			{
				rt->al->clr.r = R;
				rt->al->clr.g = G;
				rt->al->clr.b = B;
			}
			else
			{
				ft_printf("Error: In cam's values of RGB\n", 1);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			ft_printf("Error: Problem with the RGB len\n", 1);
			exit(EXIT_FAILURE);
		}
		deallocate(ptr);
	}
	else
	{
		ft_printf("Error: RGB input problem in camera\n", 1);
		exit(EXIT_FAILURE);
	}
}
// void     ft_Alight(char *line, t_rt *rt)
// {
//     int     ratio;
//     char    **ptr;

//     ptr = ft_split(line, ' ');
//     rt->al = malloc(sizeof(t_abt_lt));
//     if (rt->al == NULL)
//     {
//         ft_printf("Error: Failed to allocate memory for ambiant light\n", 1);
//         exit(EXIT_FAILURE); // Quit the program
//     }
//     if(rt->al != NULL)
//     {
//         ratio = ft_atof(ptr[1]);
//         if (ratio < 0.0 || ratio > 1.0)
//         {
//             ratio = EXIT_FAILURE;
//             ft_printf("Error: ratio's range should be at [0.0,1.0]\n", 1);
//             exit(1);
//         }
//         rt->al->brightness = ratio;
//     //     if(rt->al->brightness == EXIT_FAILURE)
//     //             exit(1);
//     //  printf("hello??");
//         ft_rgb_al(ptr[2], rt);
//         deallocate(ptr);
//     }
//     else
//     {
//         ft_printf("Error: From parsing the  Ambiant light\n", 1);
//         exit(EXIT_FAILURE);
//     }
// }
void	ft_Alight(char *line, t_rt *rt)
{
	double	ratio;
	char	**ptr;

	ptr = ft_split2(line);
	rt->al = malloc(sizeof(t_abt_lt));
	if (rt->al == NULL)
	{
		ft_printf("Error: Failed to allocate memory for ambient light\n", 1);
		exit(EXIT_FAILURE); // Quit the program
	}
	if (rt->al != NULL)
	{
		ratio = ft_atof(ptr[1]);
		if (ratio < 0.0 || ratio > 1.0)
		{
			ft_printf("Error: Ambiant light's Ratio range should be btw [0.0,
				1.0]\n", 1);
			exit(1);
		}
		rt->al->brightness = ratio;
		if (rt->al->brightness == 1337)
			exit(1);
		ft_rgb_al(ptr[2], rt);
		deallocate(ptr);
	}
	else
	{
		ft_printf("Error: Failed to allocate memory for ambient light\n", 1);
		exit(EXIT_FAILURE);
	}
}
