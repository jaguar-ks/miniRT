/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:29:23 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/10 01:10:38 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

char *SearchString(char **array, const char *needle)
{
    int i;
    int     numStrings;
    
    i = 0;
    numStrings = mtx_len(array);
    while(i < numStrings)
    {
        if (!ft_strncmp(array[i], needle, ft_strlen(needle)))
            return(array[i]);
        i++;
    }
    return(NULL);
}

int countWords(char* str) 
{
    int wordCount;
    bool word;

    wordCount = 0;
    word = false;
    while (*str != '\0') 
    {
        if (ft_isspace(*str)) 
            word = false;
        else if (!word)
        {
            word = true;
            wordCount++;
        }
        str++;
    }
    return (wordCount);
}

void	ft_valid(char *str)
{
	int i;

	i = 0;
	while (str[i])
    {
        if ( ft_isdigit(str[i]) || ft_isspace(str[i]) || str[i] == '-')
            i++;
        else
        {
            ft_printf("Error: invalid input in ft_atoi from '%s'\n", 1, str);
            exit(EXIT_FAILURE);
        }
    }
}

int countDigits(int num) {
    int count = 0;
    
    // Handle the case of zero separately
    if (num == 0) {
        return 1;
    }
    
    // Count the digits by continuously dividing by 10
    while (num != 0) {
        num /= 10;
        count++;
    }
    
    return count;
}

double ft_atof(const char* str) 
{
    double  result = 0.0;
    double  sign = 1.0;
    int     decimalFound = 0;
    double  decimalPlace = 0.1;
    
    while (ft_isspace(*str))
        str++;
    if (count_negative(str) > 1)
    {
        ft_printf("Error: invalid input in ft_atof from '%s'\n", 1, str);
        exit(1337);
    }
    if (*str == '-')
    { 
        sign = -1.0;
        str++;
    }
    while (*str != '\0') 
    {
        if (ft_isdigit(*str)) 
        {
            if (!decimalFound) 
                result = result * 10.0 + (*str - '0');
            else
            { 
                result = result + (*str - '0') * decimalPlace;
                decimalPlace *= 0.1;
            }
        } 
        else if (*str == '.')
            decimalFound = 1;
        else 
        {
            printf("Error ft_atof: wrong input str: '%s'\n", str);
            return(1337);
        }
        str++;
    }
    if (result > DBL_MAX || result < -DBL_MAX) 
    {
        printf("Error: floating-point overflow ft_atof\n");
        exit(1337);
    }
    return result * sign;
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while(str[i])
        write(1, &str[i++], 1);
}

void printf_tab(t_rt *rt)
{
    printf("/*   ABIENT LIGHT   */\n");
    printf("-brightness:\n");
    printf("   -%f\n", rt->al->brightness);
    printf("-RGB:\n");
    printf("   -R: %d\n", rt->al->clr.r);
    printf("   -G: %d\n", rt->al->clr.g);
    printf("   -B: %d\n", rt->al->clr.b);
    
    printf("*   CAMERA   */\n");
    printf("-fov:\n");
    printf(  " -%d\n", rt->cam->fov);
    printf("-cordination:\n");
    printf("   -x: %0.f\n", rt->cam->crd.x);
    printf("   -y: %0.f\n", rt->cam->crd.y);
    printf("   -z: %0.f\n", rt->cam->crd.z);
    printf("-vector:\n");
    printf("   -x: %f\n", rt->cam->nrml_vctr.x);
    printf("   -y: %f\n", rt->cam->nrml_vctr.y);
    printf("   -z: %f\n", rt->cam->nrml_vctr.z);
    
    printf("/*     LIGHT   */\n");
    printf("-RGB:\n");
    printf("   -R: %d\n", rt->lt->clr.r);
    printf("   -G: %d\n", rt->lt->clr.g);
    printf("   -B: %d\n", rt->lt->clr.b);
    printf("-cordination:\n");
    printf("   -x: %0.f\n", rt->lt->crd.x);
    printf("   -y: %0.f\n", rt->lt->crd.y);
    printf("   -z: %0.f\n", rt->lt->crd.z);
    printf("-Brightness: %f\n", rt->lt->bright);
}

int count_negative(const char *str)
{
	int i;
	int count;

    i = 0;
    count = 0;
	while (str[i])
	{
		if (str[i] == '-')
			count++;
		i++;
	}
	return (count);
}
long M_ft_atoi(const char *str)
{
    int     i;
    int     s;
    long    r;
    
    i = 0;
    s = 1;
    r = 0;
    ft_valid((char *)str);
    while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
           || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
        i++;
    if (count_negative(str) > 1)
    {
        ft_printf("Error: invalid input in ft_atoi from '%s'\n", 1, str);
        exit(EXIT_FAILURE);
    }
    if (str[i] == '-')
    {
        s *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        r = (r * 10) + (str[i] - '0');
        i++;
    }
    return (r * s);
}
