// void ft_pl(t_rt *rt, int num_planes)
// {
//     char *pl_elements;
//     char **array;
//     int i;

//     i = 0;

//     pl_elements = extractElements(rt->fl, "pl ", num_planes);
//     array = ft_split(pl_elements, '\n');

//     if (array != NULL && ft_checkWords_4(array))
//     {
//         for (i = 0; array[i] != NULL; i++)
//         {
//             char **pl_values = ft_split2(array[i]);

//             if (pl_values != NULL && mtx_len(pl_values) == 4)
//             {
//                 t_plane *plane = malloc(sizeof(t_plane));
//                 if (!plane)
//                 {
//                     ft_printf("Error: Failed to allocate memory for plane\n",
	1);
//                     exit(EXIT_FAILURE);
//                 }

//                 ft_pl_Cordination(pl_values[1], plane);
//                 ft_pl_vector(pl_values[2], plane);
//                 ft_rgb_pl(pl_values[3], plane);
	// Assuming the RGB values are in pl_values[3]

//                 // Add the plane object to the t_object linked list
//                 add_Obj(rt, plane, PLANE);

//                 deallocate(pl_values);
//             }
//             else
//             {
//                 ft_printf("Error: Invalid PL values\n", 1);
//                 exit(EXIT_FAILURE);
//             }
//         }

//         for (t_object *obj = rt->object; obj != NULL; obj = obj->next)
//         {
//             t_plane *plane = (t_plane *)obj->objct;
//             printf("RGB-> %d %d %d\nAddress: %p\n", plane->clr.r,
	plane->clr.g, plane->clr.b, (void *)plane);
//             printf("Cordination-> %f %f %f\nAddress: %p\n", plane->crd.x,
	plane->crd.y, plane->crd.z, (void *)plane);
//         }
//     }
//     else
//     {
//         ft_printf("Error: Invalid array or words\n", 1);
//         exit(EXIT_FAILURE);
//     }
// }