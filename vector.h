#ifndef VECTOR_H
# define VECTOR_H
    typedef struct s_vector
    {
        double x;
        double y;
        double z;
    }t_vector;
    
    t_vector initialize_vector(double x, double y, double z);
    t_vector add(t_vector v1, t_vector v2);
    t_vector minus(t_vector v1, t_vector v2);
    t_vector substract(t_vector v1, t_vector v2);
    t_vector multiple(double t, t_vector v);
    double  scalar(t_vector v1, t_vector v2);
    t_vector v_product(t_vector v1, t_vector v2);
    t_vector make_unit_vector(t_vector v);
    double squared_length(t_vector v);
    double length(t_vector v);

#endif