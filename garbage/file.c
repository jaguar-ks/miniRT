/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:43:40 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/08 14:24:26 by nbouljih         ###   ########.fr       */
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
//         {"C ", ft_Cam, 4},
//         {"L ", ft_light, 4}
//     };
//     i = 0;
//     while (i < sizeof(lines) / sizeof(lines[0]))
//     {
//         tmp = SearchString(rt->fl, lines[i].prefix);
//         if (tmp == NULL)
//         {
//             printf("Error: Unable to find '%s' line\n", lines[i].prefix);
//             exit(1);
//         }
//         if (!(lines[i].count ^ countWords(tmp))) {
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