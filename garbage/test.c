/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:36:00 by nbouljih          #+#    #+#             */
/*   Updated: 2023/05/21 13:45:09 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// char* searchInDoublePointer(char** str, int numStrings, const char* target) {
//     int i;
//     // for (i = 0; i < numStrings; i++) {
//     //     if (strncmp(str[i], target, strlen(target)) == 0) {
//     //         return str[i];
//     //     }
//     // }
//     i = 0;
//     while(i < numStrings)
//     {
//         if(!strncmp(str[i], target, strlen(target)))
//             return (str[i]);
//         i++;
//     }
//     return NULL; // Return NULL if the target string is not found
// }

// int main() {
//     char* str[] = {"apple", "banana hahah hoy aah", "cherry", "date"};
//     int numStrings = sizeof(str) / sizeof(str[0]);
//     printf("%d\n", numStrings);
//     const char* target = "banana";
//     char* result = searchInDoublePointer(str, numStrings, target);

//     if (result != NULL) {
//         printf("Found: %s\n", result);
//     } else {
//         printf("Not found\n");
//     }

//     return 0;
// }
// int countWords(char* str) 
// {
//     int wordCount;
//     bool word;

//     wordCount = 0;
//     word = false;
//     while (*str != '\0') 
//     {
//         if (ft_isspace(*str)) 
//             word = false;
//         else if (!word)
//         {
//             word = true;
//             wordCount++;
//         }
//         str++;
//     }
//     return (wordCount);
// }

int main(void)
{
    int i;
    char str[]= "hwllo how are you 5 6 7 ";
    i = countWords(str);
    printf("%d\n", i);
}