/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:31:30 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/10 18:07:59 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	add_obj(t_object **lst, void *object, int type)
{
	t_object	*cur_node;
	t_object	*n_obj;
	static int	i;

	n_obj = malloc(sizeof(t_object));
	if (!n_obj)
		ft_exit("Error: allocation error for object\n", 2);
	n_obj->objct = object;
	n_obj->type = type;
	n_obj->next = NULL;
	if (lst && !(*lst))
	{
		*lst = n_obj;
		i++;
	}
	else
	{
		cur_node = *lst;
		while (cur_node->next)
		{
			cur_node = cur_node->next;
			i++;
		}
		cur_node->next = n_obj;
	}
}
