#include "ray.h"

ray initialize_ray(t_vector A, t_vector B)
{
    ray R;
    R.A = A;
    R.B = B;
    R.distance = 1e30f;
    return (R);
}

t_vector ray_origine(ray R) { return R.A; }
t_vector ray_direction(ray R) { return R.B; }
t_vector line_point(ray R, double t) { return add(R.A, multiple(t, R.B));}