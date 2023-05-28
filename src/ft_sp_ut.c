/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sp_ut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:31:00 by nbouljih          #+#    #+#             */
/*   Updated: 2023/05/28 18:44:04 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void    ft_sp_rgb(char *rgb_string, t_sphere *sp)
{
    int R;
    int G;
    int B;
    char **rgb_values;

    R = 0;
    G = 0;
    B = 0;

    rgb_values = ft_split(rgb_string, ','); // Split the RGB values

    if (rgb_values != NULL && mtx_len(rgb_values) == 3) 
    {
        if (ft_strlen(rgb_values[0]) <= 3 && ft_strlen(rgb_values[1]) <= 3 && ft_strlen(rgb_values[2]) <= 3)
        {
            R = M_ft_atoi(rgb_values[0]);
            G = M_ft_atoi(rgb_values[1]);
            B = M_ft_atoi(rgb_values[2]);
             if (R >= 0 && R <= 255 && G >= 0 && G <= 255 && B >= 0 && B <= 255)
            {
                sp->clr.r = R;
                sp->clr.g = G;
                sp->clr.b = B;
            }
            else
            {
                ft_printf("Error: Invalid RGB values in plane\n", 2);
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            ft_printf("Error: Problem with the RGB length\n", 2);
            exit(EXIT_FAILURE);
        }
        deallocate(rgb_values);
    }
    else
    {
        ft_printf("Error: RGB problem in camera\n", 2);
        exit(EXIT_FAILURE);
    }
}

void    ft_sp_cord(char *string, t_sphere *rt)
{
    char **ptr;

    ptr = ft_split(string, ',');
    if(ptr == NULL || mtx_len(ptr) != 3)
    {
        ft_printf("Error: allocation comming form : [ft_pl_vec]\n", 2);
        exit(1);
    }
    else
    {
        rt->crd.x = ft_atof(ptr[0]);
        rt->crd.y = ft_atof(ptr[1]);
        rt->crd.z = ft_atof(ptr[2]);
        deallocate(ptr);
    }
}