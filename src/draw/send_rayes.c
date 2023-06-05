/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_rayes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:43:00 by faksouss          #+#    #+#             */
/*   Updated: 2023/06/05 05:22:44 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/minirt.h"

int	is_a_hit(void *obj, ObjectType type, t_ray *ray, double *t)
{
	if (type == SPHERE)
		return (check_sph_intersection((t_sphere *)obj, ray, t));
	if (type == PLANE)
		return (check_pln_intersection((t_plane *)obj, ray, t));
	if (type == CYLENDER)
		return (check_cyl_intersection((t_cylender *)obj, ray, t));
	return (0);
}

int	pix_color(void *hold, ObjectType type)
{
	t_sphere	*sp;
	t_plane		*pl;
	t_cylender  *cy;

	if (type == SPHERE)
	{
		sp = (t_sphere *)hold;
		return (encode_rgb(&sp->clr));
	}
	if (type == PLANE)
	{
		pl = (t_plane *)hold;
		return (encode_rgb(&pl->clr));
	}
	if (type == CYLENDER)
	{
		cy = (t_cylender *)hold;
		return (encode_rgb(&cy->clr));
	}
	return (0);
}

int	find_pix_color(t_rt *rt, t_ray *ray)
{
	double		cls;
	double		t;
	t_object	*obj;
	t_object	*hold;

	hold = NULL;
	obj = rt->object;
	cls = DBL_MAX;
	while (obj != NULL)
	{
		if (is_a_hit(obj->objct, obj->type, ray, &t) && (cls > t))
        {
            cls = t;
			hold = obj;
        }
		obj = obj->next;
	}
	if (hold)
		return (pix_color(hold->objct, hold->type));
	else
	{
		rt->al->clr.b *= rt->al->brightness * 10;
		rt->al->clr.g *= rt->al->brightness * 10;
		rt->al->clr.r *= rt->al->brightness * 10;
		return (encode_rgb(&rt->al->clr));
	}
}

// void	print_cam_ray(t_scn *scn, t_ray *ray, int i , int j)
// {
// 	printf("_________________________________________________\n");
// 	printf("[%d][%d]\n", i ,j);
// 	printf("cam position: %f, %f, %f\n", scn->pst.x,
//		scn->pst.y, scn->pst.z);
// 	printf("cam forwerd: %f, %f, %f\n", scn->frwrd.x,
//	scn->frwrd.y, scn->frwrd.z);
// 	printf("cam up: %f, %f, %f\n", scn->up.x, scn->up.y, scn->up.z);
// 	printf("cam rght: %f, %f, %f\n", scn->rght.x, scn->rght.y, scn->rght.z);
// 	printf("hight retion: %f\n", scn->hg);
// 	printf("wight retion: %f\n", scn->wg);
// 	printf("aspect retion: %f\n", scn->aspct_rt);
// 	printf("FOV: %f\n", scn->v_agl);
// 	printf("ray origine: %f, %f, %f\n", ray->org.x, ray->org.y, ray->org.z);
// 	printf("ray diraction: %f, %f, %f\n", ray->drct.x,
//	ray->drct.y, ray->drct.z);
// 	printf("_________________________________________________\n");
// }

void	send_rays(t_rt *rt, t_scn *scn)
{
	int		i;
	int		j;
	double	x;
	double	y;
	t_ray	ray;

	i = HIGHT;
	ray.org = scn->pst;
	while (--i > 0)
	{
		j = WIGHT;
		while (--j > 0)
		{
			x = (((double)i) * 2) / HIGHT - 1;
			y = (((double)j) * 2) / WIGHT - 1;
			ray.drct = add_vctr(add_vctr(vctr_scl(scn->rght, -x * scn->hg),
						vctr_scl(scn->up, y * scn->wg)), scn->frwrd);
			ray.drct = unit_vctr(ray.drct);
			img_pix_put(rt->mlx->img, i, j, find_pix_color(rt, &ray));
		}
	}
}
