/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:09:54 by faksouss          #+#    #+#             */
/*   Updated: 2023/06/11 01:19:55 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	encode_rgb(t_rgb *cl)
{
	if (cl->r > 255)
		cl->r = 255;
	if (cl->g > 255)
		cl->g = 255;
	if (cl->b > 255)
		cl->b = 255;
	if (cl->r < 0)
		cl->r = 0;
	if (cl->g < 0)
		cl->g = 0;
	if (cl->b < 0)
		cl->b = 0;
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

int	out(t_rt *rt)
{
	t_object	*tmp;

	mlx_destroy_image(rt->mlx->mlx, rt->mlx->img->mlx_img);
	mlx_clear_window(rt->mlx->mlx, rt->mlx->win);
	mlx_destroy_window(rt->mlx->mlx, rt->mlx->win);
	free(rt->al);
	free(rt->cam);
	free(rt->lt);
	free(rt->mlx->img);
	free(rt->mlx);
	tmp = rt->object;
	while (rt->object)
	{
		rt->object = rt->object->next;
		free(tmp->objct);
		free(tmp);
		tmp = rt->object;
	}
	exit(0);
	return (0);
}

int	out_k(int k, t_rt *rt)
{
	t_object	*tmp;

	if (k == 53)
	{
		mlx_destroy_image(rt->mlx->mlx, rt->mlx->img->mlx_img);
		mlx_clear_window(rt->mlx->mlx, rt->mlx->win);
		mlx_destroy_window(rt->mlx->mlx, rt->mlx->win);
		free(rt->al);
		free(rt->cam);
		free(rt->lt);
		free(rt->mlx->img);
		free(rt->mlx);
		tmp = rt->object;
		while (rt->object)
		{
			rt->object = rt->object->next;
			free(tmp->objct);
			free(tmp);
			tmp = rt->object;
		}
		exit(0);
	}
	return (0);
}
