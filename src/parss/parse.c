/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:59:48 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/11 03:28:15 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	check_alpha(char **string)
{
	int	i;
	int	c_a;
	int	c_c;
	int	c_l;

	c_a = 0;
	c_c = 0;
	c_l = 0;
	i = 0;
	while (string[i])
	{
		if (string[i][0] == 'A')
			c_a++;
		else if (string[i][0] == 'C')
			c_c++;
		else if (string[i][0] == 'L')
			c_l++;
		i++;
	}
	if ((c_a != 1 || c_l != 1 || c_c != 1))
	{
		printf("Error: Multiple or less occurrences of A, C, or L\n");
		exit(EXIT_FAILURE);
	}
}

t_lines	init_lines(char *s, void func(char *, t_rt *), int i)
{
	t_lines	l;

	l.prefix = s;
	l.function = func;
	l.count = i;
	return (l);
}

void	get_alpha(t_rt *rt)
{
	char	*tmp;
	size_t	i;
	t_lines	lines[3];

	lines[0] = init_lines("A ", ft_alight, 3);
	lines[1] = init_lines("C ", ft_cam, 4);
	lines[2] = init_lines("L ", ft_light, 4);
	i = 0;
	while (i < sizeof(lines) / sizeof(lines[0]))
	{
		tmp = search_string(rt->fl, lines[i].prefix);
		if (tmp == NULL)
		{
			printf("Error: Unable to find '%s' line\n", lines[i].prefix);
			exit(1);
		}
		if (!(lines[i].count ^ count_words(tmp)))
			lines[i].function(tmp, rt);
		else
		{
			printf("Error: Invalid format for '%s' line\n", lines[i].prefix);
			exit(1);
		}
		i++;
	}
}

void	len_elem(char **string, int *pl, int *sp, int *cy)
{
	char	*ptr;
	int		i;

	i = 0;
	while (string[i])
	{
		ptr = trim(string[i]);
		if (!ft_strncmp(ptr, "pl ", strlen("pl ")))
			(*pl)++;
		else if (!ft_strncmp(ptr, "sp ", strlen("sp ")))
			(*sp)++;
		else if (!ft_strncmp(ptr, "cy ", strlen("cy ")))
			(*cy)++;
		i++;
		free(ptr);
	}
}

void	init_rt(t_rt *rt)
{
	check_alpha(rt->fl);
	get_alpha(rt);
	parse_obj(rt);
}
