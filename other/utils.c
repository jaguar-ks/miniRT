/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:07:25 by nbouljih          #+#    #+#             */
/*   Updated: 2023/05/21 12:30:17 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// int ft_len(char *str)
// {
//     int i;

//     if (!str)
//         printf("Error: From strig passded in the following function : ft_strlen\n");
//     i = 0;
//     while(str[i])
//         i++;
//     return(i);
// }

// void *ft_memcpy(void *restrict dst, const void *src, size_t n)
// {
//     void    *new_str;

//     if (!dst || !src)
//         return(NULL);
//     new_str = dst;
//     while(n--)
//         *((char *)dst++) = *((char *)src++);
//     return(new_str); 
// }
// char	*ft_strstr1(const char *haystack, const char *needle)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	if (needle[0] == '\0')
// 		return ((char *)haystack);
// 	while (haystack[i] != '\0')
// 	{
// 		j = 0;
// 		while (haystack[i + j] == needle[j] && haystack[i + j] != '\0')
// 		{
// 			if (needle[j + 1] == '\0')
// 				return ((char *)&haystack[i]);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// int ft_isspace(int c)
// {
//     if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
//         return(c);
//     return(0);
// }