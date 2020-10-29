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

int planeHandler(ray r, t_objects *p, double *distance, double *t, t_objects *lights, int color)
{
    t_Plane pl;

    *t = equationPlane(r, p, distance);
    if (*t > 0)
    {
		pl = *(t_Plane*)p->content;
    	if (scalar(r.B, pl.plane_norm) > 0)
			pl.plane_norm = multiple(-1, pl.plane_norm);	
		return colorCalculator(r, pl.color_plane, *t, lights, pl.plane_norm);
	}
	return (color);
}

int squareHandler(ray r, t_objects *p, double *distance, double *t, t_objects *lights, int color)
{
    t_Square sq;

    *t = equationSquare(r, p, distance);
	if (*t >= 0)
	{
		sq = *((t_Square*)p->content);
		if (scalar(r.B, sq.square_norm) > 0)
			sq.square_norm = multiple(-1, sq.square_norm);	
		return colorCalculator(r, sq.color_square, *t, lights, sq.square_norm);
	}
    return (color);
}

int cylinderHandler(ray r, t_objects *p, double *distance, double *t, t_objects *lights, int color)
{
    t_Cylinder cy;
	t_passage_cy pass;

    pass = equationCylinder(r, p, distance);
	*t = pass.t;
	if (*t >= 0)
	{
		cy = *((t_Cylinder*)p->content);
		return colorCalculator(r, cy.cylinder_color, *t, lights, pass.N);
	}
    return (color);
}

int triangleHandler(ray r, t_objects *p, double *distance, double *t, t_objects *lights, int color)
{
    t_Triangle tr;

    *t = equationTriangle(r, p, distance);
    if (*t > 0)
    {
		tr = *(t_Triangle*)p->content;
		t_vector V1 = subtract(tr.second_point, tr.first_point);
		t_vector V2 = subtract(tr.third_point, tr.first_point);
		t_vector V = make_unit_vector(v_product(V1, V2));
		if (scalar(r.B, V) > 0)
			V = multiple(-1, V);	
		return colorCalculator(r, tr.triangle_color, *t, lights, V);
	}
	return (color);
}