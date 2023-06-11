/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:43:40 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/11 01:19:38 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void     _alight(char *line, t_rt *rt)
// {
//     int     ratio;
//     char    **ptr;
    
//     ptr = ft_split(line, ' ');
//     rt->al = malloc(sizeof(t_abt_lt));
//     if (rt->al == NULL)
//     {
//         ft_printf("Error: Failed to allocate memory for ambiant light\n", 1);
//         exit(EXIT_FAILURE); // Quit the program
//     }
//     if(rt->al != NULL)
//     {
//         ratio = ft_atof(ptr[1]);
//         if (ratio < 0.0 || ratio > 1.0)
//         {
//             ratio = EXIT_FAILURE;
//             ft_printf("Error: ratio's range should be at [0.0,1.0]\n", 1);
//             exit(1);
//         }
//         rt->al->brightness = ratio;
//     //     if(rt->al->brightness == EXIT_FAILURE)
//     //             exit(1);
//     //  printf("hello??");
//         ft_rgb_al(ptr[2], rt);
//         deallocate(ptr);
//     }
//     else
//     {
//         ft_printf("Error: From parsing the  Ambiant light\n", 1);
//         exit(EXIT_FAILURE);
//     }
// }
// void len_elem(char **string, int *pl, int *sp, int *cy)
// {
//     int i = 0;
//     while (string[i])
//     {
//         if (!ft_strncmp(space(string[i]), "pl ", ft_strlen("pl ")))
//             (*pl)++;
//         else if (!ft_strncmp(string[i], "sp ", ft_strlen("sp ")))
//             (*sp)++;
//         else if (!ft_strncmp(string[i], "cy ", ft_strlen("cy ")))
//             (*cy)++;
//         else if (ft_strncmp(string[i], "A ", ft_strlen("A ")) && ft_strncmp(string[i], "C ", ft_strlen("C ")) && ft_strncmp(string[i], "L ", ft_strlen("L ")) && !ft_isspace(string[i][0]))
//         {
//             ft_printf("Error: Unknown object type\n", 2);
//             exit(EXIT_FAILURE);
//         }
//         i++;
//     }
// }

// void get_alpha(t_rt *rt)
// {
//     char    *tmp;
//     size_t     i;
//     t_lines lines[] = {
//         {"A ", ft_alight, 3},
//         {"C ", ft_cam, 4},
//         {"L ", ft_light, 4}
//     };
//     i = 0;
//     while (i < sizeof(lines) / sizeof(lines[0]))
//     {
//         tmp = search_string(rt->fl, lines[i].prefix);
//         if (tmp == NULL)
//         {
//             printf("Error: Unable to find '%s' line\n", lines[i].prefix);
//             exit(1);
//         }
//         if (!(lines[i].count ^ count_words(tmp))) {
//             lines[i].function(tmp, rt);
//         } 
//         else 
//         {
//             printf("Error: Invalid format for '%s' line\n", lines[i].prefix);
//             exit(1);
//         }
//         i++;
//     }
// }

// int	countdigits(int num)
// {
// 	int	count;

// 	count = 0;
// 	if (num == 0)
// 		return (1);
// 	while (num != 0)
// 	{
// 		num /= 10;
// 		count++;
// 	}
// 	return (count);
// }


void	print_objects(t_rt *rt)
{
	int			objCount;
	// t_plane		*plane;
	// t_sphere	*sphere;

	objCount = 1;
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
        if (obj->type == SPHERE)
        {
            t_sphere *sphere = (t_sphere *)obj->objct;
            printf("Object Type: Sphere\n");
            printf("Sphere Color: RGB(%d, %d, %d)\n", sphere->clr.r, sphere->clr.g, sphere->clr.b);
            printf("Sphere crd: (%f, %f, %f)\n", sphere->crd.x, sphere->crd.y, sphere->crd.z);
            printf("Sphere dmt: %f\n", sphere->dmt);
        }
        if (obj->type == CYLENDER)
        {
            t_cylender *cylender = (t_cylender *)obj->objct;
            printf("Object Type: Cylender\n");
            printf("Cylender Crd: (%f, %f, %f)\n", cylender->crd.x, cylender->crd.y, cylender->crd.z);
            printf("Cylender Vector: (%f, %f, %f)\n", cylender->nrm.x, cylender->nrm.y, cylender->nrm.z);
            printf("Cylender Diameter: (%f)", cylender->dmt);
            printf("Cylender Height: (%f)\n", cylender->hgt);
            printf("Cylender Clolor: RGB(%d, %d, %d)\n", cylender->clr.r, cylender->clr.g, cylender->clr.b);
        }
        printf("\n");
        objCount++;
    }
}

// void	ft_sp_rgb(char *rgb_string, t_sphere *sp)
// {
// 	int		r;
// 	int		g;
// 	int		b;
// 	char	**rgb_values;

// 	r = 0;
// 	g = 0;
// 	b = 0;
// 	rgb_values = ft_split(rgb_string, ',');
// 	if (rgb_values != NULL && mtx_len(rgb_values) == 3)
// 	{
// 		if (ft_strlen(rgb_values[0]) <= 3 && ft_strlen(rgb_values[1]) <= 3
// 			&& ft_strlen(rgb_values[2]) <= 3)
// 		{
// 			r = m_ft_atoi(rgb_values[0]);
// 			g = m_ft_atoi(rgb_values[1]);
// 			b = m_ft_atoi(rgb_values[2]);
// 			if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255)
// 			{
// 				sp->clr.r = r;
// 				sp->clr.g = g;
// 				sp->clr.b = b;
// 			}
// 			else
// 				ft_exit("Error: Invalid RGB values in plane\n", 2);
// 		}
// 		else
// 			ft_exit("Error: Problem with the RGB length\n", 2);
// 		deallocate(rgb_values);
// 	}
// 	else
// 		ft_exit("Error: RGB problem in camera\n", 2);
// }


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
// 			add_obj(&rt->object, (void *)cy, CYLENDER);
//             deallocate(cy_val);
// 		}
// 		i++;
// 	}
//     deallocate(array);
// }