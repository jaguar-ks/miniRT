/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:31:30 by nbouljih          #+#    #+#             */
/*   Updated: 2023/05/28 20:35:32 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void add_Obj(t_object **lst, void* object, int type)
{
    t_object    *currentNode;
    t_object    *n_obj;
    static int i;
    
    n_obj = malloc(sizeof(t_object));
    if (!n_obj)
    {
        ft_printf("Error: allocation error for object\n", 2);
        exit(EXIT_FAILURE);
    }
    n_obj->objct = object;
    n_obj->type = type;
    n_obj->next = NULL;
    if (lst || *lst) 
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
void print_objects(t_rt *rt)
{
    if (rt == NULL || rt->object == NULL)
    {
        printf("No objects allocated.\n");
        return;
    }

    int objCount = 1;
    for (t_object *obj = rt->object; obj != NULL; obj = obj->next)
    {
        printf("Object %d:\n", objCount);
        if (obj->type == PLANE)
        {
            t_plane *plane = (t_plane *)obj->objct;
            printf("Object Type: Plane\n");
            printf("Plane Color: RGB(%d, %d, %d)\n", plane->clr.r, plane->clr.g, plane->clr.b);
            printf("Plane Coordinates: (%f, %f, %f)\n", plane->crd.x, plane->crd.y, plane->crd.z);
        }
        // else if (obj->type == SPHERE)
        // {
        //     t_sphere *sphere = (t_sphere *)obj->objct;
        //     printf("Object Type: Sphere\n");
        //     printf("Sphere Color: RGB(%d, %d, %d)\n", sphere->clr.r, sphere->clr.g, sphere->clr.b);
        //     printf("Sphere Center: (%f, %f, %f)\n", sphere->center.x, sphere->center.y, sphere->center.z);
        //     printf("Sphere Radius: %f\n", sphere->radius);
        // }
        // Add more else if conditions for other object types

        printf("\n");
        objCount++;
    }
}