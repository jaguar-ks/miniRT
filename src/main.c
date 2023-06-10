/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:08:53 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/10 01:02:59 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

char	**read_file(char *fl)
{
	char	*r;
	char	**sp;

	r = NULL;
	r = read_all_lines(fl);
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

void	ft_leaks(t_rt rt)
{
	free(rt.al);
	free(rt.cam);
	free(rt.lt);
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
}

void	detect_memory_leaks(void)
{
	system("leaks  minirt");
}

int	main(int ac, char **av)
{
	if (ac == 2)
		minirt(av[1]);
	else
	{
		ft_printf("Error : Bad number of args\n", 2);
		exit(EXIT_FAILURE);
	}
	detect_memory_leaks();
}
