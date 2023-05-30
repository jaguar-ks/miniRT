/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:45:38 by faksouss          #+#    #+#             */
/*   Updated: 2023/05/30 13:40:58 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/minirt.h"

void    init_scene(t_scn **scn, t_rt *rt)
{
    if (scn && *scn)
    {
        (*scn)->pst = rt->cam->crd;
        (*scn)->aspct_rt = (double)HIGHT / (double)WIGHT;
        (*scn)->v_agl = dgr_to_rd(rt->cam->fov);
        (*scn)->hg = tan((*scn)->v_agl / 2) * 2;
        (*scn)->wg = (*scn)->hg * (*scn)->aspct_rt;
        (*scn)->frwrd = rt->cam->nrml_vctr;
        (*scn)->up = unit_vctr(cros_prdct((*scn)->frwrd, (t_vctr){0, 1, 0}));
        (*scn)->rght = unit_vctr(cros_prdct((*scn)->frwrd, (*scn)->up));
    }
}

void    init_img(t_mlx_tools *mlx)
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

void    init_mlx(t_mlx_tools *mlx)
{
    mlx->mlx = mlx_init();
    mlx->win = mlx_new_window(mlx->mlx, HIGHT, WIGHT, "MINIRT");
    init_image(mlx;
}

void    render(t_rt *rt)
{
    t_scn   *scn;

    scn = (t_scn *)malloc(sizeof(t_scn));
    if (!scn)
    {
        ft_printf("Error : Allocation failed\n", 2);
        exit(EXIT_FAILURE);
    }
    init_scene(&scn, rt);
    init_mlx(rt->mlx);
    send_rays(rt, scn);
}
