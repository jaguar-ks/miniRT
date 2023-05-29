/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:02:38 by nbouljih          #+#    #+#             */
/*   Updated: 2023/05/29 05:27:16 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include"../libtool/inc/libft.h"
#include "../get_next_line/get_next_line.h"
// # include<mlx.h>
#include <stdbool.h>
#include <float.h>

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
    double   x;
    double   y;
    double   z;
}   t_crd;

/*   RGB COLORS   */
typedef struct s_rgb
{
    int r;
    int g;
    int b;
}   t_rgb;

typedef t_crd t_vctr;
/*   ABIENT LIGHT   */
typedef struct s_abt_lt
{
    double   brightness;
    t_rgb   clr;
}   t_abt_lt;

/*   CAMERA   */
typedef struct s_cam
{
    t_crd       crd;
    t_vctr      nrml_vctr;
    int         fov;
}   t_cam;

/*   LIGHT   */
typedef struct s_light
{
    t_crd   crd;
    double   bright;
    t_rgb   clr;
}   t_light;

/*   SPHERE   */
typedef struct s_sphere
{
    t_crd   crd;
    double   dmt;
    t_rgb   clr;
}   t_sphere;

/*   PLANE   */
typedef struct s_plane
{
    t_crd   crd;
    t_vctr  nrml_vctr;
    t_rgb   clr;
}   t_plane;

/*   CYLENDER   */
typedef struct s_cylender
{
    t_crd   crd;
    t_vctr   nrml_vctr;
    double   dmt;
    double   hgt;
    t_rgb   clr;
}   t_cylender;

typedef enum{
    SPHERE,
    PLANE,
    CYLENDER   
} ObjectType;

typedef struct s_object
{
    void            *objct;
    ObjectType      type;
    struct s_object *next;
}   t_object;

typedef struct s_rt
{
    t_mlx_tools mlx;
    char        **fl;
    t_abt_lt    *al;
    t_cam       *cam;
    t_light     *lt;
    t_object    *object;
}   t_rt;

typedef struct s_line{
    const char *prefix;
    void (*function)(char *, t_rt *);
    int count;
} t_lines;

typedef struct s_count
{
    int pl;
    int ps;
    int cy;
}t_count;

char    *SearchString(char **array, const char *needle);
int     ft_Double_strlen(char **array);
int     countWords(char* str);
void    init_rt(t_rt *rt);
void    ft_Alight(char *line, t_rt *rt);
double  ft_atof(const char *str);
void    ft_putstr(char *str);
void    ft_Cam(char *string, t_rt *rt);
int	    mtx_len(char **mx);
void    ft_light(char *tmp, t_rt *rt);
void    printf_tab(t_rt *rt);
long	M_ft_atoi(const char *str);
int     count_negative(const char *str);
char    **ft_split2(char *str);
void    *ft_realloc(void* ptr, size_t new_size);
void     ft_pl(t_rt *rt, int count);
void    add_Obj(t_object **lst, void* object, int type);
char    *extractElements(char** str, const char* elementPrefix, int h_m_elements);
int     ft_checkWords_4(char **array);
void    ft_pl_Cordination(char *string, t_plane *rt);
void    parse_obj(t_rt *rt);
void    len_elem(char **string,int *pl, int *sp, int *cy);
void    print_objects(t_rt *rt);
void    ft_pl_vec(char *string, t_plane *rt);
void    ft_sp_cord(char *string, t_sphere *rt);
int     ft_checkWords_6(char **array);
void    ft_sp_rgb(char *rgb_string, t_sphere *sp);
void    ft_sp(t_rt *rt, int count);
void    ft_cy(t_rt *rt, int count);
void    ft_cy_rgb(char *rgb_string, t_cylender *cy);
void    ft_cy_vec(char *string, t_cylender *rt);
void    ft_cy_cord(char *string, t_cylender *rt);
#endif
