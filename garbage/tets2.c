/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tets2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:16:57 by nbouljih          #+#    #+#             */
/*   Updated: 2023/05/22 17:25:35 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
double ft_tof(const char* str) {
    double result = 0.0f;
    double sign = 1.0f;
    int decimalFound = 0;
    double decimalPlace = 0.1f;

    while (ft_isspace(*str))
        str++;
    if (*str == '-' || *str == '+') {
        if (*str == '-')
            sign = -1.0f;
        str++;
    }
    while (*str != '\0') 
    {
        if (ft_isdigit(*str)) 
        {
            if (!decimalFound) 
                result = result * 10.0f + (*str - '0');
            else
            { 
                result = result + (*str - '0') * decimalPlace;
                decimalPlace *= 0.1f;
            }
        } 
        else if (*str == '.')
            decimalFound = 1;
        else 
        {
                printf("Error ft_atof: wrong input str: %s\n", str);
            break;
        }
        str++;
    }

    return result * sign;
}

int main() {
    const char* str = "3.14159";
    double result = ft_tof(str);

    printf("Converted double value: %f\n", result);

    return 0;
}


// void ft_Cam_Coordination(char *string, t_rt *rt)
// {
//     char **ptr;

//     ptr = ft_split(string, ',');
//     if (ptr != NULL && mtx_len(ptr) == 3)
//     {
//         rt->cam->crd.x = ft_atof(ptr[0]);
//         rt->cam->crd.y = ft_atof(ptr[1]);
//         rt->cam->crd.z = ft_atof(ptr[2]);
//         deallocate(ptr);
//     }
//     else
//     {
//         printf("Error: Invalid camera coordinates\n");
//         exit(EXIT_FAILURE); // Quit the program
//     }
// }