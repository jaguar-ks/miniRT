/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:37:12 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/11 03:13:38 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static char	*extract_word(char *str)
{
	int		word_len;
	char	*word;

	word_len = 0;
	while (*str && !is_delimiter(*str))
	{
		word_len++;
		str++;
	}
	word = malloc((word_len + 1) * sizeof(char));
	ft_strncpy(word, str - word_len, word_len);
	word[word_len] = '\0';
	return (word);
}

char	**ft_split2(char *str)
{
	int		num_words;
	char	**words;
	int		word_index;
	bool	in_word;

	num_words = count_words(str);
	words = malloc((num_words + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	word_index = 0;
	in_word = false;
	while (*str)
	{
		if (is_delimiter(*str))
			in_word = false;
		else if (!in_word)
		{
			in_word = true;
			words[word_index++] = extract_word(str);
		}
		str++;
	}
	words[word_index] = NULL;
	return (words);
}

char	*ft_strcat(char *dest, const char *src)
{
	char	*dest_ptr;

	dest_ptr = dest;
	while (*dest_ptr != '\0')
	{
		dest_ptr++;
	}
	while (*src != '\0')
	{
		*dest_ptr = *src;
		dest_ptr++;
		src++;
	}
	*dest_ptr = '\0';
	return (dest);
}

int	ft_ch_words_for(char **array)
{
	int		n_words;
	char	**words;
	int		i;

	i = 0;
	while (array[i] != NULL)
	{
		words = ft_split2(array[i]);
		n_words = mtx_len(words);
		if (n_words != 4)
		{
			deallocate(words);
			return (0);
		}
		deallocate(words);
		i++;
	}
	return (1);
}

int	ft_ch_words_six(char **array)
{
	int		n_words;
	char	**words;
	int		i;

	i = 0;
	while (array[i] != NULL)
	{
		words = ft_split2(array[i]);
		n_words = mtx_len(words);
		if (n_words != 6)
		{
			deallocate(words);
			return (0);
		}
		deallocate(words);
		i++;
	}
	return (1);
}
