#ifndef CAMERA_H
# define CAMERA_H
#include "vector.h"
#include "ray.h"
    typedef struct s_camera
    {
        t_vector start_point;
        t_vector horizontal;
        t_vector vertical;
        t_vector origine;
    }t_camera;
    t_camera initialize_camera();
    t_camera initialize_camera1(double fov, double aspect);
    t_camera iCam(t_vector lookfrom, t_vector lookat, \
            double fov, int xResolution, int yResolution);
    
#endif