/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:55:18 by faksouss          #+#    #+#             */
/*   Updated: 2023/05/20 17:48:09 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include"../libtool/inc/libft.h"
# include<mlx.h>

typedef enum{
    ABIENT_LIGHT,
    CAMERA,
    LIGHT,
    SPHERE,
    PLANE,
    CYLENDER    
} ObjectType;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct f_mlx_tools{
    void *mlx;
    void *win;
    t_img *img;
} t_mlx_tools;

/*   CORDINATIONS   */
typedef struct s_crd
{
    float   x;
    float   y;
    float   z;
}   t_crd;

/*   RGB COLORS   */
typedef struct s_rgb
{
    int r;
    int g;
    int b;
}   t_rgb;

/*   ABIENT LIGHT   */
typedef struct s_abt_lt
{
    float   brightness;
    t_rgb   clr;
}   t_abt_lt;

/*   CAMERA   */
typedef struct s_cam
{
    t_crd   crd;
    t_crd   nrml_vctr;
    int     fov;
}   t_cam;

/*   LIGHT   */
typedef struct s_light
{
    t_crd   crd;
    float   bright;
    t_rgb   clr;
}   t_light;

/*   SPHERE   */
typedef struct s_sphere
{
    t_crd   crd;
    float   dmt;
    t_rgb   clr;
}   t_sphere;

/*   PLANE   */
typedef struct s_plane
{
    t_crd   crd;
    t_crd   nrml_vctr;
    t_rgb   clr;
}   t_plane;

/*   CYLENDER   */
typedef struct s_cylender
{
    t_crd   crd;
    t_crd   nrml_vctr;
    float   dmt;
    float   hgt;
    t_rgb   clr;
}   t_cylender;

typedef struct s_rt
{
    t_mlx_tools mlx;
    char        **fl;
    t_abt_lt    *al;
    t_cam       *cam;
    t_light     *lt;
    t_plane     *pl;
    t_cylender  *cl;
    t_sphere    *sp;
}   t_rt;

#endif
