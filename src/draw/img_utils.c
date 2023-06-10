/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:09:54 by faksouss          #+#    #+#             */
/*   Updated: 2023/06/04 21:06:16 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/minirt.h"

int	encode_rgb(t_rgb *cl)
{
    return (cl->r << 16 | cl->g << 8 | cl->b);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
    char    *pixel;

    if (x * y >= HIGHT * WIGHT)
        return ;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(unsigned int *)pixel = color;
}
