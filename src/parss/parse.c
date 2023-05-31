/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:59:48 by nbouljih          #+#    #+#             */
/*   Updated: 2023/05/31 10:25:00 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void    check_Alpha(char **string)
{
    int i;
    int c_a;
    int c_c;
    int c_l;

    c_a = 0;
    c_c = 0;
    c_l = 0;
    i = 0;
    while(string[i])
    {
        if (string[i][0] == 'A')
            c_a++;
        else if (string[i][0] == 'C')
            c_c++;
        else if(string[i][0] == 'L')
            c_l++;
        i++;
    }
    if ((c_a != 1 || c_l != 1 || c_c != 1))
    {
        printf("Error: Multiple or less occurrences of A, C, or L\n");
        exit(EXIT_FAILURE);
    }
}

void get_Alpha(t_rt *rt)
{
    char    *tmp;
    size_t     i;
    t_lines lines[] = {
        {"A ", ft_Alight, 3},
        {"C ", ft_Cam, 4},
        {"L ", ft_light, 4}
    };
    i = 0;
    while (i < sizeof(lines) / sizeof(lines[0]))
    {
        tmp = SearchString(rt->fl, lines[i].prefix);
        if (tmp == NULL)
        {
            printf("Error: Unable to find '%s' line\n", lines[i].prefix);
            exit(1);
        }
        if (!(lines[i].count ^ countWords(tmp))) {
            lines[i].function(tmp, rt);
        } 
        else 
        {
            printf("Error: Invalid format for '%s' line\n", lines[i].prefix);
            exit(1);
        }
        i++;
    }
}
void    len_elem(char **string,int *pl, int *sp, int *cy)
{
    int i;

    i = 0;
    while(string[i])
    {
        if (!ft_strncmp(string[i], "pl ", ft_strlen("pl ")))
            (*pl)++;
        else if (!ft_strncmp(string[i], "sp ", ft_strlen("sp ")))
            (*sp)++;
        else if(!ft_strncmp(string[i], "cy ", ft_strlen("cy ")))
            (*cy)++;
        i++;
    }
 
}
void init_rt(t_rt *rt)
{
    // char    **tok;

    check_Alpha(rt->fl);
    get_Alpha(rt);
    // printf_tab(rt);
    parse_obj(rt);
}
