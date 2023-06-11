/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 21:15:39 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/11 03:10:02 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	val_rgb(char **rgb_values, int *r, int *g, int *b)
{
	if (ft_strlen(rgb_values[0]) <= 3 && ft_strlen(rgb_values[1]) <= 3
		&& ft_strlen(rgb_values[2]) <= 3)
	{
		*r = m_ft_atoi(rgb_values[0]);
		*g = m_ft_atoi(rgb_values[1]);
		*b = m_ft_atoi(rgb_values[2]);
		if (*r >= 0 && *r <= 255 && *g >= 0 && *g <= 255 && *b >= 0
			&& *b <= 255)
		{
			return (1);
		}
		else
			ft_exit("Error: Invalid RGB values in plane\n", 2);
	}
	else
		ft_exit("Error: Problem with the RGB length\n", 2);
	return (0);
}

void	assign_rgb(t_plane *pl, int r, int g, int b)
{
	pl->clr.r = r;
	pl->clr.g = g;
	pl->clr.b = b;
}

void	ft_rgb_pl(char *rgb_string, t_plane *pl)
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
		if (val_rgb(rgb_values, &r, &g, &b))
			assign_rgb(pl, r, g, b);
		deallocate(rgb_values);
	}
	else
		ft_exit("Error: RGB problem in camera\n", 2);
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
			ft_exit("Error: Failed to allocate memory for plane\n", 1);
		if (pl_valu != NULL && mtx_len(pl_valu) == 4)
		{
			ft_pl_cordination(pl_valu[1], plane);
			ft_pl_vec(pl_valu[2], plane);
			ft_rgb_pl(pl_valu[3], plane);
			add_obj(&rt->object, (void *)plane, PLANE);
		}
		else
			ft_exit("Error: Invalid PL values\n", 2);
		deallocate(pl_valu);
		i++;
	}
	deallocate(array);
}

void	ft_pl(t_rt *rt, int count)
{
	char	*pl_elem;
	char	**array;

	pl_elem = extract_elem(rt->fl, "pl ", count);
	array = ft_split(pl_elem, '\n');
	free(pl_elem);
	if (array != NULL && ft_ch_words_for(array))
		get_pl(array, rt);
	else
	{
		deallocate(array);
		ft_printf("Error: Invalid array or words in pl\n", 2);
		exit(1);
	}
}
