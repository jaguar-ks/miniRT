/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:31:30 by nbouljih          #+#    #+#             */
/*   Updated: 2023/05/31 10:41:41 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	add_Obj(t_object **lst, void *object, int type)
{
	t_object	*currentNode;
	t_object	*n_obj;
	static int	i;

	n_obj = malloc(sizeof(t_object));
	if (!n_obj)
	{
		ft_printf("Error: allocation error for object\n", 2);
		exit(EXIT_FAILURE);
	}
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
		currentNode = *lst;
		while (currentNode->next)
		{
			currentNode = currentNode->next;
			i++;
		}
		currentNode->next = n_obj;
	}
}
void	print_objects(t_rt *rt)
{
	int			objCount;
	t_plane		*plane;
	t_sphere	*sphere;

	if (rt == NULL || rt->object == NULL)
	{
		printf("No objects allocated.\n");
		return ;
	}
	objCount = 1;
	for (t_object *obj = rt->object; obj != NULL; obj = obj->next)
	{
		printf("Object %d:\n", objCount);
		if (obj->type == PLANE)
		{
			plane = (t_plane *)obj->objct;
			printf("Object Type: Plane\n");
			printf("Plane Color: RGB(%d, %d, %d)\n", plane->clr.r, plane->clr.g,
				plane->clr.b);
			printf("Plane Coordinates: (%f, %f, %f)\n", plane->crd.x,
				plane->crd.y, plane->crd.z);
		}
		if (obj->type == SPHERE)
		{
			sphere = (t_sphere *)obj->objct;
			printf("Object Type: Sphere\n");
			printf("Sphere Color: RGB(%d, %d, %d)\n", sphere->clr.r,
				sphere->clr.g, sphere->clr.b);
			printf("Sphere crd: (%f, %f, %f)\n", sphere->crd.x, sphere->crd.y,
				sphere->crd.z);
			printf("Sphere dmt: %f\n", sphere->dmt);
		}
		if (obj->type == CYLENDER)
			printf("Object Type: Cylender\n");
		// Add more else if conditions for other object types
		printf("\n");
		objCount++;
	}
}
