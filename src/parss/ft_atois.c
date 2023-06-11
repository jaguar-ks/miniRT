/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atois.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:27:52 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/11 01:19:38 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || ft_isspace(str[i]) || str[i] == '-')
			i++;
		else
		{
			ft_printf("Error: invalid input in ft_atoi from '%s'\n", 1, str);
			exit(EXIT_FAILURE);
		}
	}
}

void	ft_er(char *s1, int i, char *s2)
{
	ft_printf("%s :'%s'\n", i, s1, s2);
	exit(EXIT_FAILURE);
}

long	m_ft_atoi(const char *str)
{
	int		i;
	int		s;
	long	r;

	i = 0;
	s = 1;
	r = 0;
	ft_valid((char *)str);
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (count_negative(str) > 1)
		ft_er("Error: atoi :", 2, (char *)str);
	if (str[i] == '-')
	{
		s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + (str[i] - '0');
		i++;
	}
	return (r * s);
}
