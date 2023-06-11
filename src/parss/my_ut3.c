/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ut3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 03:13:14 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/11 03:17:28 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

bool	is_delimiter(char c)
{
	return (ft_isspace(c));
}

int	count_words(char *str)
{
	int		count;
	bool	in_word;

	count = 0;
	in_word = false;
	while (*str)
	{
		if (is_delimiter(*str))
		{
			in_word = false;
		}
		else if (!in_word)
		{
			in_word = true;
			count++;
		}
		str++;
	}
	return (count);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	space(const char *string)
{
	int	i;

	i = 0;
	while (string[i] && ft_isspace(string[i]))
		i++;
	return (i);
}
