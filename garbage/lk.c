/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lk.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:53:13 by nbouljih          #+#    #+#             */
/*   Updated: 2023/05/24 15:38:34 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_rgb(char *string, t_rt *rt) 
{
    int R;
    int G;
    int B;
    char **ptr;

    R = 0;
    G = 0;
    B = 0;
    ptr = ft_split(string, ',');
    if (ptr != NULL) 
    {
        R = ft_atoi(ptr[0]);
        G = ft_atoi(ptr[1]);
        B = ft_atoi(ptr[2]);
        free(ptr); 
    }
    if (R >= 0 && R <= 255)
        rt->al->clr.r = R;
    if (G >= 0 && G <= 255)
        rt->al->clr.g = G;
    if (B >= 0 && B <= 255)
        rt->al->clr.b = B;
}
void     ft_Alight(char *line, t_rt *rt)
{
    char **ptr;
    
    ptr = ft_split(line, ' '); 
    rt->al = malloc(sizeof(t_abt_lt));
    if(rt->al != NULL)
        {
            rt->al->brightness = ft_atof(ptr[1]);
            ft_rgb(ptr[2], rt);
        }
    else
        printf("oops");
    // printf("%f\n", rt->al->brightness);
    printf("R: %d\n", rt->al->clr.r);
    printf("G: %d\n", rt->al->clr.g);
    printf("B: %d\n", rt->al->clr.b);
}
void    init_rt(t_rt *rt)
{
    char    *tmp;
    int     C1;
    int     C2;

    C1 = 3;
    tmp = SearchString(rt->fl, "A "); //doesn't alloc
    if(!(C1 ^ countWords(tmp)))
        {
            ft_Alight(tmp, rt);
            free(tmp);
        }
    else
        printf("Error: from parse\nLine "); 
}