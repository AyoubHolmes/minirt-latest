#include "miniRT.h"

int sphereHandler(ray r, t_objects *p, double *distance, double *t, t_objects *lights, int color, t_p_shadow *t_shadow)
{
	t_vector newStart;
	t_vector N;

    *t = equationSphere(r, p, distance);
    if (*t > 0)
    {
        t_shadow->newStart = line_point(r, *t);
        N = make_unit_vector(substract(t_shadow->newStart ,(*(t_Sphere*)p->content).sphere_center));
		t_shadow->color_shadow = (*(t_Sphere*)p->content).color_sphere;
		color = colorCalculator(r, t_shadow->color_shadow, *t, lights, N);
    }
    return (color);
}

int planeHandler(ray r, t_objects *p, double *distance, double *t, t_objects *lights, int color, t_p_shadow *t_shadow)
{
    t_Plane pl;

    *t = equationPlane(r, p, distance);
    if (*t > 0)
    {
		t_shadow->newStart = line_point(r, *t);
		pl = *(t_Plane*)p->content;
		t_shadow->color_shadow = pl.color_plane;
    	if (scalar(r.B, pl.plane_norm) > 0)
			pl.plane_norm = multiple(-1, pl.plane_norm);	
		color = colorCalculator(r, pl.color_plane, *t, lights, pl.plane_norm);
	}
	return (color);
}

int squareHandler(ray r, t_objects *p, double *distance, double *t, t_objects *lights, int color, t_p_shadow *t_shadow)
{
    t_Square sq;

    *t = equationSquare(r, p, distance);
	if (*t >= 0)
	{
		t_shadow->newStart = line_point(r, *t);
		sq = *((t_Square*)p->content);
		t_shadow->color_shadow = sq.color_square;
		if (scalar(r.B, sq.square_norm) > 0)
			sq.square_norm = multiple(-1, sq.square_norm);	
		color = colorCalculator(r, sq.color_square, *t, lights, sq.square_norm);
	}
    return (color);
}

int cylinderHandler(ray r, t_objects *p, double *distance, double *t, t_objects *lights, int color, t_p_shadow *t_shadow)
{
    t_Cylinder cy;
	t_passage_cy pass;

    pass = equationCylinder(r, p, distance);
	*t = pass.t;
	if (*t >= 0)
	{
		t_shadow->newStart = line_point(r, *t);
		cy = *((t_Cylinder*)p->content);
		t_shadow->color_shadow = cy.cylinder_color;
		color = colorCalculator(r, cy.cylinder_color, *t, lights, pass.N);
	}
    return (color);
}

int triangleHandler(ray r, t_objects *p, double *distance, double *t, t_objects *lights, int color, t_p_shadow *t_shadow)
{
    t_Triangle tr;

    *t = equationTriangle(r, p, distance);
    if (*t > 0)
    {
		tr = *(t_Triangle*)p->content;
		t_vector V1 = substract(tr.second_point, tr.first_point);
		t_vector V2 = substract(tr.third_point, tr.first_point);
		t_vector V = make_unit_vector(v_product(V1, V2));
		if (scalar(r.B, V) > 0)
			V = multiple(-1, V);	
		return colorCalculator(r, tr.triangle_color, *t, lights, V);
	}
	return (color);
}