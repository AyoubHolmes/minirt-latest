#include "miniRT.h"

int sphereHandler(ray r, t_objects *p, double *distance, double *t, t_objects *lights, int color)
{
    *t = equationSphere(r, p, distance);

    if (*t > 0)
    {
        t_vector newStart = line_point(r, *t);
        t_vector N = make_unit_vector(subtract(newStart ,(*(t_Sphere*)p->content).sphere_center));
		return colorCalculator(r, (*(t_Sphere*)p->content).color_sphere, *t, lights, N);
    }
    return (color);
}

int planeHandler(ray r, t_objects *p, double *distance, double *t, t_objects *lights)
{
    t_Plane pl;

    *t = equationPlane(r, p, distance);
	pl = *(t_Plane*)p->content;
    if (scalar(r.B, pl.plane_norm) > 0)
	{
		pl.plane_norm = multiple(-1, pl.plane_norm);	
	}
	return colorCalculator(r, pl.color_plane, *t, lights, pl.plane_norm);
}
