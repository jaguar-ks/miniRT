/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:31:27 by nbouljih          #+#    #+#             */
/*   Updated: 2023/05/18 09:22:27 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../inc/Prase.h"

void    ft_error(int fd, char *context)
{
    printf("Error: Problem during allocation\n");
    free(context);
    close(fd);
    exit(1);
}
char    *ft_getContext(char *input, int fd)
{
    get_c   cont;
    size_t  new_capacity;
    char    *new_context;

    cont.context = NULL;
    cont.context_size = 0;
    cont.context_capacity  = 0;

   //we start by openning the file
   fd = open(input, O_RDONLY);
   if (-1 == fd)
   {
        perror("open");
        return(NULL);
   }
   // Read the file contents into a dynamically allocated string
   while((cont.bytes_read = read(fd, cont.buffer, BUFFER_SIZE)))
   {
        if (cont.bytes_read + cont.context_size > cont.context_capacity)
        {
            new_capacity = (cont.bytes_read + cont.context_capacity) + 1;
            new_context = (char *)malloc(new_capacity * sizeof(char));
            if (!new_context)
                ft_error(fd, cont.context);
            if (cont.context_size > 0 )
            {
                ft_memcpy(new_context, cont.context, cont.context_size);
                free(cont.context);
            }
            cont.context = new_context;
            cont.context_capacity = new_capacity;
        }
        ft_memcpy(cont.context + cont.context_size, cont.buffer, cont.bytes_read);
        cont.context_size += cont.bytes_read;
    }
    close(fd);
    if (cont.context)
        cont.context[cont.context_size] = '\0';
    free(new_context);
    return (cont.context);
}
void    ft_getInput();
void    ft_parce(char *input, int fd)
{
    char *Context;

    Context = ft_getContext(input, fd);
    if (!Context)
        printf("Error: There was a problem during the reading of the file\n~>The error occured from the parce\n");
    ft_getInput(Context);
}