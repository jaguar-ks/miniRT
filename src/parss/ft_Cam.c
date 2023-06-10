/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Cam.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:34:45 by nbouljih          #+#    #+#             */
/*   Updated: 2023/06/10 01:29:50 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	ft_rangeCheck(t_crd *vec)
{
	return (vec->x < -1.0f || vec->x > 1.0f || vec->y < -1.0f || vec->y > 1.0f
		|| vec->z < -1.0 || vec->z > 1.0f);
}

void	ft_Cam_Vector(char *string, t_rt *rt)
{
    char **ptr;
    ptr = ft_split(string, ',');
    if (ptr != NULL && mtx_len(ptr) == 3)
    {
        if ((ft_atof(ptr[0])) == 1337 || (ft_atof(ptr[1])) == 1337 ||
                 (ft_atof(ptr[2])) == 1337)
        {
            printf("wtf\n");
            exit(1);
        }
        else
        {
            rt->cam->nrm.x = ft_atof(ptr[0]);
            rt->cam->nrm.y = ft_atof(ptr[1]);
            rt->cam->nrm.z = ft_atof(ptr[2]);
            if(ft_rangeCheck(&(rt->cam->nrm)))
            {
                ft_printf("Error: Invalid camera vectors range sould be btw [-1,1] for each x,y,z\n", 1);
                exit(EXIT_FAILURE);
            }
            deallocate(ptr);
        }
    }
    else
    {
        printf("Error: in camera's vector\n");
        exit(EXIT_FAILURE); // Quit the program
    }
}

void	ft_CAm_cordCheck(char **ptr, t_rt *rt)
{
	if (ptr != NULL && mtx_len(ptr) == 3)
	{
		if ((rt->cam->crd.x = ft_atof(ptr[0])) == 1337
			|| (rt->cam->crd.y = ft_atof(ptr[1])) == 1337
			|| (rt->cam->crd.z = ft_atof(ptr[2])) == 1337)
		{
			printf("Error : atof\n");
			exit(1);
		}
	}
}
void	ft_Cam_Coordination(char *string, t_rt *rt)
{
	char	**ptr;

	ptr = ft_split(string, ',');
	if (ptr != NULL && mtx_len(ptr) == 3)
	{
		ft_CAm_cordCheck(ptr, rt);
		rt->cam->crd.x = ft_atof(ptr[0]);
		rt->cam->crd.y = ft_atof(ptr[1]);
		rt->cam->crd.z = ft_atof(ptr[2]);
		deallocate(ptr);
	}
	else
	{
		ft_printf("Error: Invalid camera coordinates\n", 1);
		exit(EXIT_FAILURE); // Quit the program
	}
}
void	ft_Cam(char *string, t_rt *rt)
{
	char	**ptr;

	rt->cam = malloc(sizeof(t_cam));
	if (rt->cam == NULL)
	{
		printf("Error: Failed to allocate memory for camera\n");
		exit(EXIT_FAILURE); // Quit the program
	}
	ptr = ft_split2(string);
	if (ptr != NULL && mtx_len(ptr) == 4)
	{
		ft_Cam_Coordination(ptr[1], rt);
		ft_Cam_Vector(ptr[2], rt);
		rt->cam->fov = M_ft_atoi(ptr[3]);
		deallocate(ptr);
	}
	else
	{
		printf("Error: Invalid camera parameters\n");
		exit(EXIT_FAILURE); // Quit the program
	}
}
