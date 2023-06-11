/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:50:18 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/11 03:10:02 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_exit(char *str, int i)
{
	ft_printf("%s\n", i, str);
	exit(EXIT_FAILURE);
}

void	put_sp(t_sphere *sp, char **ptr)
{
	ft_sp_cord(ptr[1], sp);
	if (ft_atof(ptr[2]) != 1337)
		sp->dmt = ft_atof(ptr[2]);
	else
	{
		ft_printf("Error: dmt in sp\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_sp_rgb(ptr[3], sp);
	deallocate(ptr);
}

void	get_sp(char **array, t_rt *rt)
{
	t_sphere	*sp;
	char		**sp_val;
	int			i;

	i = 0;
	while (array[i])
	{
		sp_val = ft_split2(array[i]);
		sp = malloc(sizeof(t_sphere));
		if (!sp)
			ft_exit("Error: Failed to allocate memory for sphere\n", 1);
		if (sp_val != NULL && mtx_len(sp_val) == 4)
		{
			put_sp(sp, sp_val);
			add_obj(&rt->object, (void *)sp, SPHERE);
		}
		else
			ft_exit("Error: Invalid SP values\n", 2);
		i++;
	}
	deallocate(array);
}

void	ft_sp(t_rt *rt, int count)
{
	char	*sp_elm;
	char	**array;

	sp_elm = extract_elem(rt->fl, "sp ", count);
	free(sp_elm);
	array = ft_split(sp_elm, '\n');
	if (array != NULL && ft_ch_words_for(array))
		get_sp(array, rt);
	else
	{
		ft_printf("Error: Invalid array or words in sp \n", 2);
		exit(EXIT_FAILURE);
	}
}
