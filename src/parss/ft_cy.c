/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:48:55 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/10 01:23:13 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	get_cy(char **array, t_rt *rt)
{
	t_cylender	*cy;
	char		**cy_val;
	int			i;

	i = 0;
	while (array[i])
	{
		cy_val = ft_split2(array[i]);
		cy = malloc(sizeof(t_cylender));
		if (!cy)
		{
			ft_printf("Error: Failed to allocate memory for cylender\n", 1);
			exit(EXIT_FAILURE);
		}
		if (cy_val != NULL && mtx_len(cy_val))
		{
			ft_cy_cord(cy_val[1], cy);
			ft_cy_vec(cy_val[2], cy);
			cy->dmt = ft_atof(cy_val[3]);
			cy->hgt = ft_atof(cy_val[4]);
			ft_cy_rgb(cy_val[5], cy);
			add_Obj(&rt->object, (void *)cy, CYLENDER);
		}
		i++;
	}
}

void	ft_cy(t_rt *rt, int count)
{
	char	*cy_val;
	char	**array;

	cy_val = extract_elem(rt->fl, "cy", count);
	array = ft_split(cy_val, '\n');
	if (array != NULL && ft_checkWords_6(array))
		get_cy(array, rt);
	else
	{
		ft_printf("Error: Invalid array or words in cy\n", 2);
		exit(1);
	}
}
