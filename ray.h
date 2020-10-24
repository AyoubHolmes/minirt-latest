#ifndef RAY_H
#define RAY_H
#include "vector.h"

typedef struct ray
{
    t_vector A;
    t_vector B;
    double  distance;
}ray;

ray initialize_ray(t_vector A, t_vector B);
t_vector ray_origine(ray R);
t_vector ray_direction(ray R);
t_vector line_point(ray R, double t);


#endif