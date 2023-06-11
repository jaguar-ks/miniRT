/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:08:53 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/10 05:36:23 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	read_fl(char *fl)
{
	int	i;

	i = ft_strlen(fl) - 1;
	if (fl[i] != 't' && fl[i - 1] != 'r' && fl[i - 2] == '.')
	{
		ft_printf("Error : Wrong file format\n", 2);
		exit(1);
	}
	return (open(fl, O_RDONLY, 0777));
}

char	**read_file(char *fl)
{
	char	*r;
	char	**sp;
	int		fd;

	r = NULL;
	fd = open(fl, (O_RDONLY), 0777);
	r = gnl(fd);
	sp = ft_split(r, '\n');
	free(r);
	return (sp);
}

void	minirt(char *fl)
{
	t_rt	rt;

	rt.fl = read_file(fl);
	if (!rt.fl || !rt.fl[0])
	{
		ft_printf("Error : empty file\n", 2);
		exit(1);
	}
	init_rt(&rt);
	deallocate(rt.fl);
	render(&rt);
}

void	hh(void)
{
	system("leaks miniRT");
}

int	main(int ac, char **av)
{
	atexit(hh);
	if (ac == 2)
		minirt(av[1]);
	else
	{
		ft_printf("Error : Bad number of args\n", 2);
		exit(EXIT_FAILURE);
	}
}
