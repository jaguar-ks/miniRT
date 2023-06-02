/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:09:54 by faksouss          #+#    #+#             */
/*   Updated: 2023/06/02 20:51:31 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/minirt.h"

int	encode_rgb(t_rgb *cl)
{
	return (cl->r << 16 | cl->g << 8 | cl->b);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x * y >= HIGHT * WIGHT)
		return ;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}
