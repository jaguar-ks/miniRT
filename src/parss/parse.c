/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:59:48 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/11 05:09:11 by faksouss         ###   ########.fr       */
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
        else if (ft_strncmp(string[i], "A ", 2) && ft_strncmp(string[i], "C ", 2)
            && ft_strncmp(string[i], "L ", 2))
            ft_exit("Error : Unknowen Object\n", 2);
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
