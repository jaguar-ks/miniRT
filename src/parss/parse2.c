/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:16:05 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/10 16:56:30 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

char	*trim(char *str)
{
	char	*ptr;
	int		i;
	int		t;
	int		j;

	t = strlen(str);
	i = space(str);
	ptr = (char *)malloc(sizeof(char) * (t - i + 1));
	j = 0;
	while (str[i])
	{
		ptr[j] = str[i];
		i++;
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

void	parse_obj(t_rt *rt)
{
	t_count	x;

	x.cy = 0;
	x.pl = 0;
	x.ps = 0;
	len_elem(rt->fl, &x.pl, &x.ps, &x.cy);
	rt->object = NULL;
	ft_pl(rt, x.pl);
	ft_sp(rt, x.ps);
	ft_cy(rt, x.cy);
}
