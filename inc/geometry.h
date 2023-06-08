/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 23:08:39 by faksouss          #+#    #+#             */
/*   Updated: 2023/06/07 23:21:27 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
#define GEOMETRY_H

#include"minirt.h"

# define EPS 0.0001

/*   CORDINATIONS   */
typedef struct s_crd
{
	double			x;
	double			y;
	double			z;
}					t_crd;

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
	t_vctr			nrml_vctr;
	t_rgb			clr;
}					t_plane;

/*   CYLENDER   */
typedef struct s_cylender
{
	t_crd			crd;
	t_vctr			nrml_vctr;
	double			dmt;
	double			hgt;
	t_rgb			clr;
}					t_cylender;

/*   RAY   */
typedef struct s_ray
{
	t_crd			org;
	t_vctr			drct;
}					t_ray;

/*   INTERSECTION   */
typedef struct s_hit_point
{
    t_vctr  nrm;
    t_vctr  nrm;
    t_ray   p_r;
    t_rgb   px_cl;
    double  t;
}   t_hit_point;

typedef struct s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef t_crd t_vctr;

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
/*********************************************/

#endif
