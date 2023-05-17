/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:07:25 by nbouljih          #+#    #+#             */
/*   Updated: 2023/05/17 11:53:40 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.hpp"

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