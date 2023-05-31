/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:14:09 by nbouljih          #+#    #+#             */
/*   Updated: 2023/05/31 17:05:54 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
void ft_rgb_l(char *string, t_rt *rt) 
{
    int R;
    int G;
    int B;
    char **ptr;

    R = 0;
    G = 0;
    B = 0;
    ptr = ft_split(string, ',');
    if (ptr != NULL && mtx_len(ptr) == 3) 
    {
        if(ft_strlen(ptr[0]) <= 3 && ft_strlen(ptr[1]) <= 3 && ft_strlen(ptr[2]) <= 3)
       {
            R = M_ft_atoi(ptr[0]);
            G = M_ft_atoi(ptr[1]);
            B = M_ft_atoi(ptr[2]);
             if (R >= 0 && R <= 255 && (G >= 0 && G <= 255) && ( B >= 0 && B <= 255))
            {
                rt->lt->clr.r = R;
                rt->lt->clr.g = G;
                rt->lt->clr.b = B;
            }
            else
            {
                ft_printf("Error: In light's values of RGB\n", 1);
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            ft_printf("Error: Problem with the RGB len\n", 1);
            exit(EXIT_FAILURE);
        }
        deallocate(ptr); 
    }
    else
    {
        ft_printf("Error: RGB problem in camera\n", 1);
        exit(EXIT_FAILURE);
    }
}
void    ft_light_cordCheck(char **ptr, t_rt *rt)
{
    if (ptr != NULL && mtx_len(ptr) == 3)
    {
        if ((rt->lt->crd.x = ft_atof(ptr[0])) == 1337 || ( rt->lt->crd.y = ft_atof(ptr[1])) == 1337 ||
                 (rt->lt->crd.z = ft_atof(ptr[2])) == 1337){
                    printf("Error : atof\n");
                    exit(1);
                 }
    }
}
void ft_light_Coordination(char *string, t_rt *rt)
{
    char **ptr;

    ptr = ft_split(string, ',');
    if (ptr != NULL && mtx_len(ptr) == 3)
    {
        ft_light_cordCheck(ptr, rt);
        rt->lt->crd.x = ft_atof(ptr[0]);
        rt->lt->crd.y = ft_atof(ptr[1]);
        rt->lt->crd.z = ft_atof(ptr[2]);
        deallocate(ptr);
    }
    else
    {
        ft_printf("Error: Invalid light coordinates\n", 1);
        exit(EXIT_FAILURE); // Quit the program
    }
}
void    ft_light(char *tmp, t_rt *rt)
{
    char    **ptr;
    
    rt->lt = malloc(sizeof(t_light));
    if(!rt->lt)
    {
        ft_printf("Error: Failed to allocate memory for light\n", 1);
        exit(EXIT_FAILURE);
    }
    ptr = ft_split2(tmp);
    if(rt->lt != NULL)
    {
        ft_light_Coordination(ptr[1], rt);
        if((rt->lt->bright = ft_atof(ptr[2]) == EXIT_FAILURE))
            exit(1);
        rt->lt->bright = ft_atof(ptr[2]);
        if (rt->lt->bright < 0.0 || rt->lt->bright > 1.0)
        {
            ft_printf("Error: the light brightness ratio should be in range [0.0,1.0]\n", 1);
            exit(1);
        }
        ft_rgb_l(ptr[3], rt);
        deallocate(ptr);
    }
}
