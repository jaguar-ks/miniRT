/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:50:18 by nbouljih          #+#    #+#             */
/*   Updated: 2023/05/31 10:25:00 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void    put_sp(t_sphere *sp, char **ptr)
{
    ft_sp_cord(ptr[1], sp);
    sp->dmt = ft_atof(ptr[2]);
    ft_sp_rgb(ptr[3], sp);
    deallocate(ptr);
}
void    get_sp(char **array, t_rt *rt)
{
    t_sphere *sp;
    char    **sp_val;
    int     i;

    i = 0;
    while (array[i])
    {
        sp_val = ft_split2(array[i]);
        sp = malloc(sizeof(t_sphere));
        if (!sp)
        {
            ft_printf("Error: Failed to allocate memory for sphere\n", 1);
            exit(EXIT_FAILURE);
        }
        if (sp_val != NULL && mtx_len(sp_val) == 4)
        { 
            put_sp(sp, sp_val);
            add_Obj(&rt->object, (void *)sp, SPHERE);    
        }
        else
        {
            ft_printf("Error: Invalid SP values\n", 2);
            exit(EXIT_FAILURE);
        }
        i++;
    }
    
}
void    ft_sp(t_rt *rt, int count)
{
    char    *sp_elm;
    char    **array;    
    sp_elm =  extractElements(rt->fl, "sp ", count);
    array = ft_split(sp_elm, '\n');
    if(!array || !ft_checkWords_4(array))
    {
        ft_printf("Error: Invalid array or words in sp \n", 2);
        exit(EXIT_FAILURE);
    }
    else
        get_sp(array, rt);
}
