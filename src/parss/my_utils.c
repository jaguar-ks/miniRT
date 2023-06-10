/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:37:12 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/10 00:46:27 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static bool is_delimiter(char c)
{
    return ft_isspace(c);
}

static int count_words(char *str)
{
    int count = 0;
    bool in_word = false;

    while (*str)
    {
        if (is_delimiter(*str))
        {
            in_word = false;
        }
        else if (!in_word)
        {
            in_word = true;
            count++;
        }
        str++;
    }

    return count;
}

static char *extract_word(char *str)
{
    int     word_len;
    char    *word;
    word_len = 0;
    while (*str && !is_delimiter(*str))
    {
        word_len++;
        str++;
    }
    word = malloc((word_len + 1) * sizeof(char));
    strncpy(word, str - word_len, word_len);//implement
    word[word_len] = '\0';
    return (word);
}

char **ft_split2(char *str)
{
    int num_words = count_words(str);
    char **words = malloc((num_words + 1) * sizeof(char *));

    if (!words)
        return NULL;

    int word_index = 0;
    bool in_word = false;

    while (*str)
    {
        if (is_delimiter(*str))
        {
            in_word = false;
        }
        else if (!in_word)
        {
            in_word = true;
            words[word_index++] = extract_word(str);
        }

        str++;
    }
    words[word_index] = NULL;
    return words;
}

char* extract_elem(char** str, const char* elementPrefix, int h_m_elements) 
{
    int count;
    char    **extract_el; 
    char    *ptr;
    size_t  extract_sz;
    char    *extract_str;
    int     i;
    
    extract_el = malloc((h_m_elements + 1) * sizeof(char*));
    if (extract_el == NULL) 
    {
        ft_printf("Error: Allocation problem from extract_elem\n", 2);
        return NULL;
    }
    count = 0;
    i = 0;
    while(str[i])
    {
        ptr = trim(str[i]);
        while (*ptr && ft_isspace(*ptr)) 
            ptr++;
        if (!ft_strncmp(ptr, elementPrefix, ft_strlen(elementPrefix))) 
        {
            extract_el[count] = ft_strdup(str[i]);
            count++;
        }
        i++;
    }
    // for (int i = 0; str[i] != NULL; i++) 
    // {
    //     ptr = trim(str[i]);
    //     while (*ptr && ft_isspace(*ptr)) 
    //         ptr++;
    //     if (!ft_strncmp(ptr, elementPrefix, ft_strlen(elementPrefix))) 
    //     {
    //         extract_el[count] = ft_strdup(str[i]);
    //         count++;
    //     }
    // }
    extract_el[count] = NULL; 
    extract_sz = 0;
    for (int i = 0; i < count; i++) {
        extract_sz += ft_strlen(extract_el[i]) + 1;  
    } 
    extract_str = malloc(extract_sz);
    if (extract_str == NULL) 
    {
        free(extract_el);
        return NULL;
    }
    extract_str[0] = '\0';  
    for (int i = 0; i < count; i++) 
    {
        strcat(extract_str, extract_el[i]); //strcat
        strcat(extract_str, "\n");
    }
    for (int i = 0; i < count; i++) 
    {
        free(extract_el[i]);
    }
    free(extract_el);
    return (extract_str);
}

int ft_checkWords_4(char **array)
{
    int numWords;
    char    **words;
    int i;
    int j;

    i = 0;
    while(array[i] != NULL)
    {
        words = ft_split2(array[i]);
        numWords = mtx_len(words);
        if (numWords != 4)
        {
            j = -1;
            while(words[j++])
                free(words[j]);
            free(words);
            return(0);
        }
        j = -1;
        while(words[j++])
            free(words[j]);
        free(words);
        i++;
    }
    return (1);
}

int ft_checkWords_6(char **array)
{
    int numWords;
    char    **words;
    int i;
    int j;

    i = 0;
    while(array[i] != NULL)
    {
        words = ft_split2(array[i]);
        numWords = mtx_len(words);
        if (numWords != 6)
        {
            j = -1;
            while(words[j++])
                free(words[j]);
            free(words);
            return(0);
        }
        j = -1;
        while(words[j++])
            free(words[j]);
        free(words);
        i++;
    }
    return (1);
}
