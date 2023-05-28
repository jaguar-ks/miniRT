/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:20:40 by nbouljih          #+#    #+#             */
/*   Updated: 2023/05/20 18:28:36 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *left_str)
{
	char	*buff;
	int		rd;

	rd = 0;
	if (!left_str[rd])
		return (NULL);
	while (left_str[rd] && left_str[rd] != '\n')
		rd++;
	buff = malloc(sizeof(char) * (rd + 2));
	if (!buff)
		return (NULL);
	rd = 0;
	while (left_str[rd] && left_str[rd] != '\n')
	{
		buff[rd] = left_str[rd];
		rd++;
	}
	if (left_str[rd] == '\n')
	{
		buff[rd] = left_str[rd];
		rd++;
	}
	buff[rd] = '\0';
	return (buff);
}

char	*ft_get_new_line(char *left_str)
{
	int		i;
	int		x;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_len(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	x = 0;
	while (left_str[i])
		str[x++] = left_str[i++];
	str[x] = '\0';
	free(left_str);
	return (str);
}

size_t	ft_len(char *str)
{
	size_t	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index] != '\0')
		index++;
	return (index);
}

char	*ft_join(char *left_str, char *buff)
{
	size_t	i;
	size_t	x;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_len(left_str) + ft_len(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	x = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[x] != '\0')
		str[i++] = buff[x++];
	str[ft_len(left_str) + ft_len(buff)] = '\0';
	free(left_str);
	return (str);
}

char	*ft_Strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_len(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
