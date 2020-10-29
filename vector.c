#include "miniRT.h"

t_vector initialize_vector(double x, double y, double z)
{
    t_vector v;
    v.x = x;
    v.y = y;
    v.z = z;
    return(v);
}

t_vector add(t_vector v1, t_vector v2)
{
    t_vector v3;
    v3.x = v1.x + v2.x;
    v3.y = v1.y + v2.y;
    v3.z = v1.z + v2.z;
    return (v3);
}

t_vector minus(t_vector v1, t_vector v2)
{
    t_vector v3;
    v3.x = v1.x - v2.x;
    v3.y = v1.y - v2.y;
    v3.z = v1.z - v2.z;
    return (v3);
}

t_vector subtract(t_vector v1, t_vector v2)
{
    t_vector v3;
    v3.x = v1.x - v2.x;
    v3.y = v1.y - v2.y;
    v3.z = v1.z - v2.z;
    return (v3);
}

t_vector multiple(double t, t_vector v)
{
    t_vector v3;
    v3.x = t * v.x;
    v3.y = t * v.y;
    v3.z = t * v.z;
    return (v3);
}

double  scalar(t_vector v1, t_vector v2)
{
    return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vector v_product(t_vector v1, t_vector v2)
{
    t_vector v3;

    v3.x = v1.y * v2.z - v1.z * v2.y;
    v3.y = v1.z * v2.x - v1.x * v2.z;
    v3.z = v1.x * v2.y - v1.y * v2.x;
    return (v3);
}

double squared_length(t_vector v)
{
    return(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
}

t_vector make_unit_vector(t_vector v)
{
    return (multiple(1/sqrt(squared_length(v)), v));
}