/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:02:29 by nbouljih          #+#    #+#             */
/*   Updated: 2023/05/18 09:05:10 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int main(int ac, char **av)
{
    int fd;

    if (ac == 2)
        {
            ft_check(av[1], fd);
            ft_parce(av[1], fd);
        }
    else
        printf("Error: a scene.tr file is required\n");
}