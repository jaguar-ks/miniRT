/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 02:08:40 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/11 03:14:36 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	deallocate_extract_el(char **extract_el)
{
	int	i;

	i = 0;
	while (extract_el[i])
	{
		free(extract_el[i]);
		i++;
	}
}

char	*concat_strings(char **str)
{
	size_t	extract_sz;
	char	*extract_str;
	int		i;

	extract_sz = 0;
	extract_str = NULL;
	i = 0;
	while (str[i])
	{
		extract_sz += ft_strlen(str[i]) + 1;
		i++;
	}
	extract_str = malloc(extract_sz);
	if (extract_str == NULL)
		return (NULL);
	extract_str[0] = '\0';
	i = 0;
	while (str[i])
	{
		ft_strcat(extract_str, str[i]);
		ft_strcat(extract_str, "\n");
		i++;
	}
	return (extract_str);
}

void	extract_and_count(char **str, const char *elementPrefix,
		char **extract_el, int *count)
{
	int		i;
	char	*ptr;

	i = 0;
	while (str[i])
	{
		ptr = trim(str[i]);
		if (!ft_strncmp(ptr, elementPrefix, ft_strlen(elementPrefix)))
		{
			extract_el[*count] = ft_strdup(str[i]);
			(*count)++;
		}
		free(ptr);
		i++;
	}
}

char	*extract_elem(char **str, const char *elementPrefix, int h_m_elements)
{
	int		count;
	char	**extract_el;
	char	*ptr;
	char	*extract_str;
	int		i;

	count = 0;
	extract_el = malloc((h_m_elements + 1) * sizeof(char *));
	ptr = NULL;
	extract_str = NULL;
	i = 0;
	if (extract_el == NULL)
		ft_exit("Error: Allocation problem from extract_elem\n", 2);
	extract_and_count(str, elementPrefix, extract_el, &count);
	extract_el[count] = NULL;
	extract_str = concat_strings(extract_el);
	i = 0;
	deallocate_extract_el(extract_el);
	return (free(extract_el), extract_str);
}

int	mtx_len(char **mx)
{
	int	i;

	i = 0;
	while (mx[i])
		i++;
	return (i);
}
