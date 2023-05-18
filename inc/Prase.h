/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Prase.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:08:09 by nbouljih          #+#    #+#             */
/*   Updated: 2023/05/18 10:20:47 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCE_H
#define PARCE_H
#include "minirt.h"

typedef enum{
    ABIENT_LIGHT,
    CAMERA,
    LIGHT,
    SPHERE,
    PLANE,
    CYLENDER    
} ObjectType;

typedef struct{
    ObjectType  type;
    union 
    {
        struct AmbientLight *ambiant;
        struct Camera       *cam;
        struct Light        *nour;
        struct Sphere       *sphere;
        struct Plane        *plane;
        struct Cylender     *cylend;
    }data;
    
};

typedef struct ambiant_light{
    float   ratio;
    int     colors[3]; //RGB
} AmbientLight;

typedef struct cam{
    float   cordination[3];//to ask fahd if they should split to becomes int or not "x,y,z coordinates of the view point"
    float   orientation[3];
    float   fov; //flied of view 
}Camera;

typedef struct light{
    float   cordinatiom[3];
    float   orientation[3];
    int     colors[3];
}Light;

typedef struct sphere{
    float   cordination[3];
    float   orientation[3];
    int colors[3];
}Sphere;

typedef struct plane{
    float   cordination[3];
    float   normalVector[3];//3d normalized normal vector
    int     colors[3];
}Plane;

typedef struct cylender{
    float   cordination[3];
    float   axiVectot[3];
    float   diameter;
    float   hight;
    int     colors[3];
}Cylender;
#endif