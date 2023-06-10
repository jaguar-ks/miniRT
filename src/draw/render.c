/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:45:38 by faksouss          #+#    #+#             */
/*   Updated: 2023/06/10 02:25:27 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_vctr	find_right_vctr(t_vctr frwrd)
{
	t_vctr	v;
	t_vctr	r;

	v = (t_vctr){0, 1, 0};
	r = cros_prdct(frwrd, v);
	if (!r.x && !r.y && !r.z)
	{
		v = (t_vctr){1, 0, 0};
		r = cros_prdct(frwrd, v);
	}
	if (!r.x && !r.y && !r.z)
	{
		v = (t_vctr){0, 0, 1};
		r = cros_prdct(frwrd, v);
	}
	return (r);
}

void	init_scene(t_scn **scn, t_rt *rt)
{
	if (scn && *scn)
	{
		(*scn)->pst = rt->cam->crd;
		(*scn)->aspct_rt = (double)HIGHT / (double)WIGHT;
		(*scn)->v_agl = dgr_to_rd(rt->cam->fov);
		(*scn)->wg = tan((*scn)->v_agl / 2);
		(*scn)->hg = (*scn)->wg * (*scn)->aspct_rt;
		(*scn)->frwrd = rt->cam->nrm;
		(*scn)->rght = unit_vctr(find_right_vctr((*scn)->frwrd));
		(*scn)->up = unit_vctr(cros_prdct((*scn)->rght, (*scn)->frwrd));
	}
}

void	init_img(t_mlx_tools *mlx)
{
	mlx->img = (t_img *)malloc(sizeof(t_img));
	if (!mlx->img)
	{
		ft_printf("Error : Allocation failed\n", 2);
		exit(EXIT_FAILURE);
	}
	mlx->img->mlx_img = mlx_new_image(mlx->mlx, HIGHT, WIGHT);
	mlx->img->addr = mlx_get_data_addr(mlx->img->mlx_img, &mlx->img->bpp,
			&mlx->img->line_len, &mlx->img->endian);
}

void	init_mlx(t_mlx_tools *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, HIGHT, WIGHT, "MINIRT");
	init_img(mlx);
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

void	render(t_rt *rt)
{
	t_scn	*scn;

	scn = (t_scn *)malloc(sizeof(t_scn));
	if (!scn)
	{
		ft_printf("Error : Allocation failed\n", 2);
		exit(EXIT_FAILURE);
	}
	init_scene(&scn, rt);
	rt->mlx = (t_mlx_tools *)malloc(sizeof(t_mlx_tools));
	init_mlx(rt->mlx);
	send_rays(rt, scn);
	free(scn);
	mlx_put_image_to_window(rt->mlx->mlx, rt->mlx->win, rt->mlx->img->mlx_img,
		0, 0);
	mlx_hook(rt->mlx->win, 17, 0, out, rt);
	mlx_key_hook(rt->mlx->win, out_k, rt);
	mlx_loop(rt->mlx->mlx);
}
