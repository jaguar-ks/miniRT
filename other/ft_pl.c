/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:40:02 by nbouljih          #+#    #+#             */
/*   Updated: 2023/05/28 18:57:19 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
// char* extractElements(char** str, const char* elementPrefix, int h_m_elements) {
//     int count ;

//     // Allocate memory for the extracted elements
//     char** extractedElements = malloc((h_m_elements + 1) * sizeof(char*));
//     if (extractedElements == NULL) 
//     {
//        ft_printf("Error: Allocation problem from extractElements\n", 1);
//         return NULL;
//     }
//     // Extract the matching elements
//     count = 0;
//     for (int i = 0; str[i] != NULL; i++) {
//         if (!ft_strncmp(str[i], elementPrefix, strlen(elementPrefix)))
//         {
//             extractedElements[count] = ft_strdup(str[i]);
//             count++;
//         }
//     }
//     extractedElements[count] = NULL;  // Null-terminate the array
//     // Concatenate the extracted elements into a single string
//     size_t extractedSize = 0;
//     for (int i = 0; i < count; i++) {
//         extractedSize += ft_strlen(extractedElements[i]) + 1;  // Account for newline character
//     } // 
//     char* extractedString = malloc(extractedSize);
//     if (extractedString == NULL) {
//         // Error handling for memory allocation failure
//         free(extractedElements);
//         return NULL;
//     }
//     extractedString[0] = '\0';  // Initialize the string as empty
//     for (int i = 0; i < count; i++) {
//         strcat(extractedString, extractedElements[i]);
//         strcat(extractedString, "\n");
//     }

//     // Free the memory allocated for the array of pointers
//     for (int i = 0; i < count; i++) {
//         free(extractedElements[i]);
//     }
//     free(extractedElements);

//     return extractedString;
// }
// int ft_checkWords_4(char **array)
// {
//     int numWords;
//     char    **words;
//     int i;
//     int j;

//     i = 0;
//     while(array[i] != NULL)
//     {
//         words = ft_split2(array[i]);
//         numWords = mtx_len(words);
//         if (numWords != 4)
//         {
//             j = -1;
//             while(words[j++])
//                 free(words[j]);
//             free(words);
//             return(0);
//         }
//         j = -1;
//         while(words[j++])
//             free(words[j]);
//         free(words);
//         i++;
//     }
//     return (1);
// }
// void ft_rgb_pl(char *rgb_string, t_plane *pl)
// {
//     int R;
//     int G;
//     int B;
//     char **rgb_values;

//     R = 0;
//     G = 0;
//     B = 0;
//     ft_printf("->%s\n",1,rgb_string);
//     rgb_values = ft_split(rgb_string, ',');
//     if (rgb_values != NULL && mtx_len(rgb_values) == 3) 
//     {
//         if (ft_strlen(rgb_values[0]) <= 3 && ft_strlen(rgb_values[1]) <= 3 && ft_strlen(rgb_values[2]) <= 3)
//         {
//             R = M_ft_atoi(rgb_values[0]);
//             G = M_ft_atoi(rgb_values[1]);
//             B = M_ft_atoi(rgb_values[2]);
//              if (R >= 0 && R <= 255 && G >= 0 && G <= 255 && B >= 0 && B <= 255)
//             {
//                 pl->clr.r = R;
//                 pl->clr.g = G;
//                 pl->clr.b = B;
//             }
//             else
//             {
//                 ft_printf("Error: Invalid RGB values in plane\n", 1);
//                 exit(EXIT_FAILURE);
//             }
//         }
//         else
//         {
//             ft_printf("Error: Problem with the RGB length\n", 1);
//             exit(EXIT_FAILURE);
//         }
//         deallocate(rgb_values);
//     }
//     else
//     {
//         ft_printf("Error: RGB problem in camera\n", 1);
//         exit(EXIT_FAILURE);
//     }
// }

// void ft_pl_cordCheck(char **ptr, t_plane *rt)
// {
//     if (ptr != NULL && mtx_len(ptr) == 3)
//     {
//         rt->crd.x = ft_atof(ptr[0]);
//         rt->crd.y = ft_atof(ptr[1]);
//         rt->crd.z = ft_atof(ptr[2]);
//     }
//     else
//     {
//         ft_printf("Error: Invalid light coordinates\n", 1);
//         exit(EXIT_FAILURE);
//     }
// }

// void ft_pl_Cordination(char *string, t_plane *rt)
// {
//     char **ptr;

//     ptr = ft_split(string, ',');
//     if (ptr != NULL && mtx_len(ptr) == 3)
//     {
//         ft_pl_cordCheck(ptr, rt);
//         deallocate(ptr);
//     }
//     else
//     {
//         ft_printf("Error: Invalid light coordinates\n", 1);
//         exit(EXIT_FAILURE);
//     }
// }
// void link_planes(t_plane *planes, int plane_count) 
// {
//     int i;

//     i = 0;
//     while(i < plane_count - 1)
//     {
//         planes[i].next = &planes[i + 1];
//         i++;
//     }
//     planes[plane_count - 1].next = NULL;
// }
// void ft_pl(t_rt *rt, int pl)
// {
//     char *Pl_elements;
//     char **array;
//     int i;

//     i = 0;
//     rt->pl = malloc(sizeof(t_plane) * pl);
//     if (!rt->pl)
//     {
//         ft_printf("Error: Failed to allocate memory for plane\n", 1);
//         exit(EXIT_FAILURE);
//     }
//     Pl_elements = extractElements(rt->fl, "pl ", pl);
//     array = ft_split(Pl_elements, '\n');
//     if (array != NULL && ft_checkWords_4(array))
//     {
//         i = 0;
//         while (array[i] != NULL)
//         {
//             char **pl_values = ft_split2(array[i]);
//             if (pl_values != NULL && mtx_len(pl_values) == 4)
//             {
//                 ft_pl_Cordination(pl_values[1], &rt->pl[i]);
//                 ft_pl_vector(pl_values[2], &rt->pl[i]);
//                 ft_rgb_pl(pl_values[3], &rt->pl[i]); // Assuming the RGB values are in pl_values[3]
//                 deallocate(pl_values);
//             }
//             else
//             {
//                 ft_printf("Error: Invalid PL values\n", 1);
//                 exit(EXIT_FAILURE);
//             }
//             i++;
//         }
//         for (int x = 0; x < i; x++)
//             printf("RGB-> %d %d %d\nAddress: %p\n", rt->pl[x].clr.r, rt->pl[x].clr.g, rt->pl[x].clr.b, (void *)&rt->pl[x]);
//         for (int x = 0; x < i; x++)
//             printf("Cordination-> %f %f %f\nAddress: %p\n", rt->pl[x].crd.x, rt->pl[x].crd.y, rt->pl[x].crd.z, (void *)&rt->pl[x]);
//         link_planes(rt->pl, i);
//     }
//     else
//     {
//         ft_printf("Error: Invalid array or words\n", 1);
//         exit(EXIT_FAILURE);
//     }
// }