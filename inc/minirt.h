/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:02:38 by nbouljih          #+#    #+#             */
/*   Updated: 2023/05/18 09:11:27 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
typedef struct getc {
    char    buffer[BUFFER_SIZE + 1];
    char    *context;
    int     ret;
    size_t  context_size;
    size_t  context_capacity;
    size_t  bytes_read;
} get_c;

int     ft_len(char *str);
void    ft_check(char *input, int fd);
void    *ft_memcpy(void *restrict dst, const void *src, size_t n);
void    ft_parce(char *input, int fd);
#endif


// r << 16 | g << 8 | b