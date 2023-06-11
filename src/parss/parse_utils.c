/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:29:23 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/10 17:31:06 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

char	*search_string(char **array, const char *needle)
{
	int	i;
	int	num_str;

	i = 0;
	num_str = mtx_len(array);
	while (i < num_str)
	{
		if (!ft_strncmp(array[i], needle, ft_strlen(needle)))
			return (array[i]);
		i++;
	}
	return (NULL);
}

// double	ft_atof(const char *str)
// {
// 	double	result;
// 	double	sign;
// 	int		found_dec;
// 	double	dec_place;

// 	result = 0.0;
// 	sign = 1.0;
// 	found_dec = 0;
// 	dec_place = 0.1;
// 	while (ft_isspace(*str))
// 		str++;
// 	if (count_negative(str) > 1)
// 	{
// 		ft_printf("Error: invalid input in ft_atof from '%s'\n", 1, str);
// 		exit(1337);
// 	}
// 	if (*str == '-')
// 	{
// 		sign = -1.0;
// 		str++;
// 	}
// 	while (*str != '\0')
// 	{
// 		if (ft_isdigit(*str))
// 		{
// 			if (!found_dec)
// 				result = result * 10.0 + (*str - '0');
// 			else
// 			{
// 				result = result + (*str - '0') * dec_place;
// 				dec_place *= 0.1;
// 			}
// 		}
// 		else if (*str == '.')
// 			found_dec = 1;
// 		else
// 		{
// 			printf("Error ft_atof: wrong input str: '%s'\n", str);
// 			return (1337);
// 		}
// 		str++;
// 	}
// 	return (result * sign);
// }

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}
