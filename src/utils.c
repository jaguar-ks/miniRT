/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:07:25 by nbouljih          #+#    #+#             */
/*   Updated: 2023/05/18 09:05:16 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int ft_len(char *str)
{
    int i;

    if (!str)
        printf("Error: From strig passded in the following function : ft_strlen\n");
    i = 0;
    while(str[i])
        i++;
    return(i);
}

void *ft_memcpy(void *restrict dst, const void *src, size_t n)
{
    void    *new_str;

    if (!dst || !src)
        return(NULL);
    new_str = dst;
    while(n--)
        *((char *)dst++) = *((char *)src++);
    return(new_str); 
}