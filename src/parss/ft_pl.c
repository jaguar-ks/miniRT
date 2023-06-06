/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 21:15:39 by nbouljih          #+#    #+#             */
/*   Updated: 2023/05/31 10:25:00 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_rgb_pl(char *rgb_string, t_plane *pl)
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
				pl->clr.r = R;
				pl->clr.g = G;
				pl->clr.b = B;
			}
			else
			{
				ft_printf("Error: Invalid RGB values in plane\n", 2);
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
void	get_pl(char **array, t_rt *rt)
{
	t_plane	*plane;
	char	**pl_valu;
	int		i;

	i = 0;
	while (array[i])
	{
		pl_valu = ft_split2(array[i]);
		plane = malloc(sizeof(t_plane));
		if (!plane)
		{
			ft_printf("Error: Failed to allocate memory for plane\n", 1);
			exit(EXIT_FAILURE);
		}
		if (pl_valu != NULL && mtx_len(pl_valu) == 4)
		{
			ft_pl_Cordination(pl_valu[1], plane);
			ft_pl_vec(pl_valu[2], plane);
			ft_rgb_pl(pl_valu[3], plane);
			deallocate(pl_valu);
			add_Obj(&rt->object, (void *)plane, PLANE);
		}
		else
		{
			ft_printf("Error: Invalid PL values\n", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
void	ft_pl(t_rt *rt, int count)
{
	char	*pl_elem;
	char	**array;

	pl_elem = extractElements(rt->fl, "pl ", count);
	array = ft_split(pl_elem, '\n');
	if (array != NULL && ft_checkWords_4(array))
		get_pl(array, rt);
	else
	{
		ft_printf("Error: Invalid array or words in pl\n", 2);
		exit(1);
	}
}
