/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:06:27 by nbouljih          #+#    #+#             */
/*   Updated: 2023/05/18 09:04:57 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int ft_extention(char *input)
{
    int i;

    i = ft_len(input) - 1;
    if(input[i] == 'r' && input[i - 1] == 't' && input[i - 2] == '.')
        return(0);
    return (printf("Error: Wrong type of file\nMust be a file of extention *.tr\n"));
}
int ft_executable(int fd, char *input)
{
    fd = open(input, O_RDONLY);
    if (-1 == fd)
        return(printf("Error: File is unexecutable, Please an other file\n"));
    close(fd);
    return(0);
}
int ft_isEmpty(char *str, int fd)
{
    int     R_bytes;
    int     F_lenght;
    char    *buff;

    fd = open(str, O_RDONLY);
    if(-1 == fd)
        {
            perror("open");
            return(1);
        }
    buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if(!buff)
        return(EXIT_FAILURE);
    F_lenght = 0;
    while((R_bytes = read(fd, buff, BUFFER_SIZE)) > 0 )
        {
            buff[R_bytes] = '\0';
            F_lenght += R_bytes;
        }
    if(F_lenght <= 0)
            return(printf("Error: Empty File\n"));
    close(fd);
    free(buff);
    return(0);
}
void    ft_check(char *input, int fd)
{
    int c = ft_extention(input) + ft_executable(fd, input) + ft_isEmpty(input, fd);
    if (c)
        exit (1);
    return ;
}