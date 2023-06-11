/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 23:17:35 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/11 03:18:29 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	count_negative(const char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '-')
			count++;
		i++;
	}
	return (count);
}

void	ft_err(char *s1, int i, char *s2)
{
	ft_printf("%s: '%s'\n", i, s1, s2);
	exit(1337);
}

double	process_number(const char **str, double result, int *found_dec,
		double *dec_place)
{
	while (**str != '\0')
	{
		if (ft_isdigit(**str))
		{
			if (!*found_dec)
				result = result * 10.0 + (**str - '0');
			else
			{
				result = result + (**str - '0') * (*dec_place);
				(*dec_place) *= 0.1;
			}
		}
		else if (**str == '.')
			*found_dec = 1;
		else
		{
			printf("Error ft_atof: wrong input str: '%s'\n", *str);
			return (1337);
		}
		(*str)++;
	}
	return (result);
}

double	ft_atof(const char *str)
{
	double	result;
	double	sign;
	int		found_dec;
	double	dec_place;

	result = 0.0;
	sign = 1.0;
	found_dec = 0;
	dec_place = 0.1;
	while (ft_isspace(*str))
		str++;
	if (count_negative(str) > 1)
		ft_err("Error: invalid input in ft_atof from\n", 2, (char *)str);
	if (*str == '-')
	{
		sign = -1.0;
		str++;
	}
	result = process_number(&str, result, &found_dec, &dec_place);
	return (result * sign);
}
