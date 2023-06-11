/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Cam.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:34:45 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/11 01:19:38 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	ft_rangecheck(t_crd *vec)
{
	return (vec->x < -1.0f || vec->x > 1.0f || vec->y < -1.0f || vec->y > 1.0f
		|| vec->z < -1.0 || vec->z > 1.0f);
}

void	ft_cam_vector(char *string, t_rt *rt)
{
	char	**ptr;

	ptr = ft_split(string, ',');
	if (ptr != NULL && mtx_len(ptr) == 3)
	{
		if ((ft_atof(ptr[0])) == 1337 || (ft_atof(ptr[1])) == 1337
			|| (ft_atof(ptr[2])) == 1337)
			ft_exit("Error: Check cam vector\n", 2);
		else
		{
			rt->cam->nrm.x = ft_atof(ptr[0]);
			rt->cam->nrm.y = ft_atof(ptr[1]);
			rt->cam->nrm.z = ft_atof(ptr[2]);
			if (ft_rangecheck(&(rt->cam->nrm)))
				ft_exit("Error: Invalid camera vectors range=[-1,1] \n", 2);
			deallocate(ptr);
		}
	}
	else
		ft_exit("Error: in camera's vector\n", 2);
}

void	ft_cam_cordcheck(char **ptr, t_rt *rt)
{
	float	x;
	float	y;
	float	z;

	if (ptr != NULL && mtx_len(ptr) == 3)
	{
		x = ft_atof(ptr[0]);
		y = ft_atof(ptr[1]);
		z = ft_atof(ptr[2]);
		if (x == 1337 || y == 1337 || z == 1337)
			ft_exit("Error: Invalid coordinate values for camera\n", 2);
		else
		{
			rt->cam->crd.x = x;
			rt->cam->crd.y = y;
			rt->cam->crd.z = z;
		}
	}
}

void	ft_cam_coordination(char *string, t_rt *rt)
{
	char	**ptr;

	ptr = ft_split(string, ',');
	if (ptr != NULL && mtx_len(ptr) == 3)
	{
		ft_cam_cordcheck(ptr, rt);
		rt->cam->crd.x = ft_atof(ptr[0]);
		rt->cam->crd.y = ft_atof(ptr[1]);
		rt->cam->crd.z = ft_atof(ptr[2]);
		deallocate(ptr);
	}
	else
		ft_exit("Error: Invalid camera coordinates\n", 2);
}

void	ft_cam(char *string, t_rt *rt)
{
	char	**ptr;

	rt->cam = malloc(sizeof(t_cam));
	if (rt->cam == NULL)
		ft_exit("Error: Failed to allocate memory for camera\n", 2);
	ptr = ft_split2(string);
	if (ptr != NULL && mtx_len(ptr) == 4)
	{
		ft_cam_coordination(ptr[1], rt);
		ft_cam_vector(ptr[2], rt);
		rt->cam->fov = m_ft_atoi(ptr[3]);
		deallocate(ptr);
	}
	else
	{
		deallocate(ptr);
		ft_exit("Error: Invalid camera parameters\n", 2);
	}
}
