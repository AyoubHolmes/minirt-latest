#include "miniRT.h"
#include <math.h>
t_camera initialize_camera()
{
    t_camera cam;
    cam.start_point = initialize_vector(-2, -1, -1);
    cam.horizontal = initialize_vector(4.0, 0.0, 0.0);
    cam.vertical = initialize_vector(0.0, 2.0, 0.0);
    cam.origine = initialize_vector(0.0, 0.0, 0.0);
    return (cam);
}

t_camera initialize_camera1(double fov, double aspect)
{
    t_camera cam;

    double theta = fov * M_PI/180;
    double half_height = tan(theta/2);
    double half_width = aspect * half_height;
    cam.start_point = (t_vector){-half_width, -half_height, -1};
    cam.horizontal = (t_vector){2*half_width, 0.0, 0.0};
    cam.vertical = (t_vector){0.0, 2*half_height, 0.0};
    cam.origine = (t_vector){0.0, 0.0, 0.0};
    return (cam);
}

ray get_ray(t_data d, double u, double v)
{
    t_camera cam = iCam(d.cameras->cam.view_point, d.cameras->cam.cam_normal,\
			 d.cameras->cam.fov, d.R.x, d.R.y);
    return initialize_ray(cam.origine, subtract(add(cam.start_point, \
        add(multiple(u, cam.horizontal), multiple(v, cam.vertical))), cam.origine));
}

t_camera iCam(t_vector lookfrom, t_vector lookat, \
            double fov, int xResolution, int yResolution)
{
    t_camera cam;
    t_vector up = (t_vector){0, 1, 0};
    t_vector u, v, w;
    double aspect = (double)xResolution / (double)yResolution;
    double theta = fov * M_PI / 180;
    double half_height = tan(theta/2);
    double half_width = aspect * half_height;
    cam.origine = lookfrom;
    w = make_unit_vector(subtract(cam.origine, lookat));
    u = make_unit_vector(v_product(w, up));
    v = v_product(w, u);
    t_vector v1 = subtract(cam.origine, multiple(half_width, u));
    t_vector v2 = add(multiple(half_height, v), w);
    cam.start_point = subtract(v1, v2);
    cam.horizontal = multiple(2 * half_width, u);
    cam.vertical = multiple(2 * half_height, v);
    return (cam);
}
