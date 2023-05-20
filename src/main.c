/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:56:21 by faksouss          #+#    #+#             */
/*   Updated: 2023/05/20 17:56:23 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/minirt.h"

int	check_and_open_file(char *fl)
{
	int i;
	
	i  = ft_strlen(fl);
	i -= 3;
	if (strcmp(fl + i, ".rt"))
	{
		ft_printf("Error : Wrong file format\n", 2);
		exit(1);
	}
	return (open(fl, O_RDONLY, 0777));
}

char    **read_file(char *fl)
{
	int     fd;
	char    *str;
	char    *r;
	char    **sp;

	r = NULL;
	fd = check_and_open_file(fl);
	if (fd < 0)
	{
		ft_printf("Error : openning the file\n", 2);
		exit(1);
	}
	while (1)
	{
		str = gnl(fd);
		if (!str)
			break ;
		r = ft_strjoin(r, str);
	}
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

void    _miniRT(char *fl)
{
	t_rt    rt;

	rt.fl = read_file(fl);
	if (!rt.fl || !rt.fl[0])
	{
		ft_printf("Error : empty file\n", 2);
		exit(1);
	}
	for (int i = 0; i < mtx_len(rt.fl); i++)
		printf("-> %s\n", rt.fl[i]);
}

int main(int ac, char **av)
{
	if (ac == 2)
		_miniRT(av[1]);
	else
	{
		ft_printf("Error : Bad number of args\n", 2);
		exit(EXIT_FAILURE);
	}
}
