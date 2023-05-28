
A  0.2        255,255,255                            
C  -50,0,20   0,0,0   70                                
L  -40,0,30   0.7    255,255,255                            
pl 0,0,0   0,1.0,0   255,0,225                              ~>Plane
sp 0,0,20   20   255,0,0                                    ~>Sphere
cy 50.0,0.0,20.6   0,0,1.0  14.2  21.42  10,0,255          ~>Cylinder

typedef struct s_plane
{
    t_crd   crd;
    t_crd   nrml_vctr;
    t_rgb   clr;
}   t_plane;

typedef struct s_cylender
{
    t_crd   crd;
    t_crd   nrml_vctr;
    double   dmt;
    double   hgt;
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

 check_elem(rt->fl); // function that returns how many pl sp and cy are in the input 
I  need a function that allocates depending on how many pl cl and sp  


// void    check_elem(char **string)
// {
//     int i;
//     int pl;
//     int sp;
//     int cy;

//     pl = 0;
//     sp = 0;
//     cy = 0;
//     i = 0;
//     while(string[i])
//     {
//         if (!ft_strncmp(string[i], "pl ", ft_strlen("pl ")))
//             pl++;
//         else if (!ft_strncmp(string[i], "sp ", ft_strlen("sp ")))
//             sp++;
//         else if(!ft_strncmp(string[i], "cy ", ft_strlen("cy ")))
//             cy++;
//         i++;
//     }
//     // printf("pl: %d\n", pl);
//     // printf("sp: %d\n", sp);
//     // printf("cy: %d\n", cy);
// }

// void    ft_pl_cordCheck(char **ptr, t_rt *rt)
// {
//     if (ptr != NULL && mtx_len(ptr) == 3)
//     {
//         if ((rt->lt->crd.x = ft_atof(ptr[0])) == EXIT_FAILURE || ( rt->lt->crd.y = ft_atof(ptr[1])) == EXIT_FAILURE ||
//                  (rt->lt->crd.z = ft_atof(ptr[2])) == EXIT_FAILURE)
//             exit(1);
//     }
// }
// void ft_pl_Coordination(char *string, t_rt *rt)
// {
//     char **ptr;

//     ptr = ft_split(string, ',');
//     if (ptr != NULL && mtx_len(ptr) == 3)
//     {
//         ft_light_cordCheck(ptr, rt);
//         rt->lt->crd.x = ft_atof(ptr[0]);
//         rt->lt->crd.y = ft_atof(ptr[1]);
//         rt->lt->crd.z = ft_atof(ptr[2]);
//         deallocate(ptr);
//     }
//     else
//     {
//         ft_printf("Error: Invalid light coordinates\n", 1);
//         exit(EXIT_FAILURE); // Quit the program
//     }
// }

// void ft_pl_cordCheck(char **ptr, t_plane *rt)
// {
//     if (ptr != NULL && mtx_len(ptr) == 3)
//     {
//         rt->crd.x = ft_atof(ptr[0]);
//         rt->crd.y = ft_atof(ptr[1]);
//         rt->crd.z = ft_atof(ptr[2]);
//     }
//     else
//     {
//         ft_printf("Error: Invalid light coordinates\n", 1);
//         exit(EXIT_FAILURE);
//     }
// }