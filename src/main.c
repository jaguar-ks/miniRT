/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:08:53 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/11 01:42:26 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int read_fl(char *fl)
{
	int	i;

	i = ft_strlen(fl) - 1;
	if (ft_strcmp(&fl[i - 2], ".rt"))
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
	int     fd;

	r = NULL;
    fd = read_fl(fl);
    if (fd < 0)
    {
        ft_printf("Error : openning the file\n", 2);
        exit(EXIT_FAILURE);
    }
	r = gnl(fd);
	sp = ft_split(r, '\n');
	free(r);
	return (sp);
}

int	mtx_len(char **mx)
{
	int	i;

	i = 0;
	while (mx[i])
		i++;
	return (i);
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

void hh(){
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
