/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:48:55 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/10 04:45:41 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

// void	get_cy(char **array, t_rt *rt)
// {
// 	t_cylender	*cy;
// 	char		**cy_val;
// 	int			i;

// 	i = 0;
// 	while (array[i])
// 	{
// 		cy_val = ft_split2(array[i]);
// 		cy = malloc(sizeof(t_cylender));
// 		if (!cy)
// 		{
// 			ft_printf("Error: Failed to allocate memory for cylender\n", 1);
// 			exit(EXIT_FAILURE);
// 		}
// 		if (cy_val != NULL && mtx_len(cy_val))
// 		{
// 			ft_cy_cord(cy_val[1], cy);
// 			ft_cy_vec(cy_val[2], cy);
//             if (ft_atof(cy_val[3]) != 1337 ||  ft_atof(cy_val[4]) != 1337)
//             {
// 			    cy->dmt = ft_atof(cy_val[3]);
//                 cy->hgt = ft_atof(cy_val[4]);
//             }
//             else
//                 exit(1);
// 			ft_cy_rgb(cy_val[5], cy);
// 			add_Obj(&rt->object, (void *)cy, CYLENDER);
//             deallocate(cy_val);
// 		}
// 		i++;
// 	}
//     deallocate(array);
// }
void get_cy(char **array, t_rt *rt)
{
t_cylender *cy;
char **cy_val;
int i;

i = 0;
while (array[i])
{
    cy_val = ft_split2(array[i]);
    cy = malloc(sizeof(t_cylender));
    if (!cy)
    {
        ft_printf("Error: Failed to allocate memory for cylender\n", 1);
        exit(EXIT_FAILURE);
    }
    if (cy_val != NULL && mtx_len(cy_val))
    {
        ft_cy_cord(cy_val[1], cy);
        ft_cy_vec(cy_val[2], cy);
        if (ft_atof(cy_val[3]) == 1337 || ft_atof(cy_val[4]) == 1337)
            exit(1);
        else
        {
            cy->dmt = ft_atof(cy_val[3]);
            cy->hgt = ft_atof(cy_val[4]);
        }
        ft_cy_rgb(cy_val[5], cy);
        add_Obj(&rt->object, (void *)cy, CYLENDER);
        deallocate(cy_val);
    }
    i++;
}
deallocate(array);
}

void	ft_cy(t_rt *rt, int count)
{
	char	*cy_val;
	char	**array;

	cy_val = extract_elem(rt->fl, "cy ", count);
    free(cy_val);
	array = ft_split(cy_val, '\n');
	if (array != NULL && ft_checkWords_6(array))
        get_cy(array, rt);
	else
	{
        deallocate(array);
		ft_printf("Error: Invalid array or words in cy\n", 2);
		exit(1);
	}
}
