/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:02:38 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/11 01:24:59 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../get_next_line/get_next_line.h"
# include "../libtool/inc/libft.h"
# include <float.h>
# include <mlx.h>
# include <stdbool.h>

# define EPS 0.0001
# define HIGHT 800
# define WIGHT 800

typedef struct s_img
{
	void			*mlx_img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
}					t_img;

typedef struct f_mlx_tools
{
	void			*mlx;
	void			*win;
	t_img			*img;
}					t_mlx_tools;

/*   CORDINATIONS   */
typedef struct s_crd
{
	double			x;
	double			y;
	double			z;
}					t_crd;

/*   RGB COLORS   */
typedef struct s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef t_crd		t_vctr;
/*   ABIENT LIGHT   */
typedef struct s_abt_lt
{
	double			brightness;
	t_rgb			clr;
}					t_abt_lt;

/*   CAMERA   */
typedef struct s_cam
{
	t_crd			crd;
	t_vctr			nrm;
	int				fov;
}					t_cam;

typedef struct s_scn
{
	t_crd			pst;
	t_vctr			frwrd;
	t_vctr			up;
	t_vctr			rght;
	double			aspct_rt;
	double			v_agl;
	double			hg;
	double			wg;
}					t_scn;

/*   LIGHT   */
typedef struct s_light
{
	t_crd			crd;
	double			bright;
	t_rgb			clr;
}					t_light;

/*   SPHERE   */
typedef struct s_sphere
{
	t_crd			crd;
	double			dmt;
	t_rgb			clr;
}					t_sphere;

/*   PLANE   */
typedef struct s_plane
{
	t_crd			crd;
	t_vctr			nrm;
	t_rgb			clr;
}					t_plane;

/*   CYLENDER   */
typedef struct s_cylender
{
	t_crd			crd;
	t_vctr			nrm;
	double			dmt;
	double			hgt;
	t_rgb			clr;
}					t_cylender;

typedef enum s_object_type
{
	SPHERE,
	PLANE,
	CYLENDER
}					t_ObjectType;

typedef struct s_object
{
	void			*objct;
	t_ObjectType	type;
	struct s_object	*next;
}					t_object;

typedef struct s_ray
{
	t_crd			org;
	t_vctr			drct;
}					t_ray;

typedef struct s_hit_point
{
	t_vctr			nrm;
	t_ray			r;
	t_rgb			px_cl;
	double			t;
}					t_hit_point;
typedef struct s_rt
{
	t_mlx_tools		*mlx;
	char			**fl;
	t_abt_lt		*al;
	t_cam			*cam;
	t_light			*lt;
	t_object		*object;
}					t_rt;

typedef struct s_line
{
	const char		*prefix;
	void			(*function)(char *, t_rt *);
	int				count;
}					t_lines;

typedef struct s_count
{
	int				pl;
	int				ps;
	int				cy;
}					t_count;

typedef struct s_read
{
	char			*line;
	char			*all_ln;
	size_t			total_si;
	int				fd;
	size_t			line_s;
	char			*temp;
}					t_read;

char				*SearchString(char **array, const char *needle);
int					ft_Double_strlen(char **array);
int					countWords(char *str);
void				init_rt(t_rt *rt);
void				ft_Alight(char *line, t_rt *rt);
double				ft_atof(const char *str);
void				ft_putstr(char *str);
void				ft_Cam(char *string, t_rt *rt);
int					mtx_len(char **mx);
void				ft_light(char *tmp, t_rt *rt);
void				printf_tab(t_rt *rt);
long				M_ft_atoi(const char *str);
int					count_negative(const char *str);
char				**ft_split2(char *str);
void				*ft_realloc(void *ptr, size_t new_size);
void				ft_pl(t_rt *rt, int count);
void				add_Obj(t_object **lst, void *object, int type);
char				*extract_elem(char **str, const char *elementPrefix,
						int h_m_elements);
int					ft_checkWords_4(char **array);
void				ft_pl_Cordination(char *string, t_plane *rt);
void				parse_obj(t_rt *rt);
void				len_elem(char **string, int *pl, int *sp, int *cy);
void				print_objects(t_rt *rt);
void				ft_pl_vec(char *string, t_plane *rt);
void				ft_sp_cord(char *string, t_sphere *rt);
int					ft_checkWords_6(char **array);
void				ft_sp_rgb(char *rgb_string, t_sphere *sp);
void				ft_sp(t_rt *rt, int count);
void				ft_cy(t_rt *rt, int count);
void				ft_cy_rgb(char *rgb_string, t_cylender *cy);
void				ft_cy_vec(char *string, t_cylender *rt);
void				ft_cy_cord(char *string, t_cylender *rt);
char				*trim(char *str);
void				ft_alight(char *line, t_rt *rt);
/*******************|MATH|********************/
t_vctr				add_vctr(t_vctr v1, t_vctr v2);
t_vctr				sub_vctr(t_vctr v1, t_vctr v2);
t_vctr				mltp_vctr(t_vctr v1, t_vctr v2);
t_vctr				vctr_scl(t_vctr v, double s);
double				dot_prdct(t_vctr v1, t_vctr v2);
double				vctr_len(t_vctr v);
t_vctr				unit_vctr(t_vctr v);
t_vctr				cros_prdct(t_vctr v1, t_vctr v2);
double				dgr_to_rd(double angle);
int					double_equality(double a, double b);
int					less_then(double *a, double b);
int					check_sph_intersection(t_sphere *sp, t_ray *ray, double *t);
int					check_pln_intersection(t_plane *sp, t_ray *ray, double *t);
int					check_cyl_intersection(t_cylender *cy, t_ray *ray,
						double *t);
t_vctr				get_nrm_att(t_object *obj, t_ray *r, t_ray *p, double t);
/*********************************************/
/*******************|drawing|********************/
void				render(t_rt *rt);
void				init_mlx(t_mlx_tools *mlx);
void				init_img(t_mlx_tools *mlx);
void				init_scene(t_scn **scn, t_rt *rt);
t_ray				make_ray(t_scn *scn, double x, double y);
int					encode_rgb(t_rgb *cl);
void				img_pix_put(t_img *img, int x, int y, int color);
void				send_rays(t_rt *rt, t_scn *scn);
int					find_pix_color(t_rt *rt, t_ray *ray);
void				init_img(t_mlx_tools *mlx);
int					no_hit(t_abt_lt *am);
int					shadow(t_abt_lt *am, t_object *obj);
int					is_a_hit(void *obj, t_ObjectType type, t_ray *ray,
						double *t);
t_rgb				add_clr(t_rgb cl1, t_rgb cl2, double r);
t_rgb				visible(t_ray *r, t_vctr nrm, t_rgb obj, t_rt *rt);
int					blind(t_ray *r, t_object *obj, t_crd l);
t_rgb				get_obj_clr(t_object *obj);
int					out_k(int k, t_rt *rt);
int					out_k(int k, t_rt *rt);
/************************************************/

#endif
