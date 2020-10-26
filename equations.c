#include "miniRT.h"

double equationSphere(ray R, t_objects *obj, double *distance)
{
	t_Sphere	*sp = ((t_Sphere*)obj->content);
	t_vector oc = subtract(R.A, sp->sphere_center);
	double a = scalar(R.B, R.B);
	double b = 2.0 * scalar(oc, R.B);
	double c = scalar(oc, oc) - pow((double)(sp->sphere_diametre / 2), 2);
	double dis = pow(b, 2) - 4 * a * c;
	double t;

	oc = subtract(R.A, sp->sphere_center);
	a = scalar(R.B, R.B);
	if (dis < 0)
	{
		return -1.0;
	}
	else
	{
		t = (-b - sqrt(dis) ) / (2.0*a);
		if (t <= *distance && t >= 0)
		{
			*distance = t;
			return (t);
		}
		return (-1);
	}
}

double equationPlane(ray R, t_objects *obj,double *distance)
{
	t_Plane *pl = ((t_Plane*)obj->content);
	t_vector oc = subtract(R.A, pl->plane_center);
	double x = scalar(R.B, pl->plane_norm);
	double y = scalar(oc, pl->plane_norm);
	double t;
	if (x != 0)
	{
		t = -y / x;
		if (t <= *distance && t >= 0)
		{
			*distance = t;
			return (t);
		}
	}
	return -1;
}

double equationSquare(ray R, t_objects *obj,double *distance)
{
	t_Square *sq = ((t_Square*)obj->content);
	t_vector oc = subtract(R.A, sq->square_center);
	double x = scalar(R.B, make_unit_vector(sq->square_norm));
	double y = scalar(oc, make_unit_vector(sq->square_norm));
	double t;
	if (fabs(x) > 0)
	{
		t = -y / x;
		t_vector v = line_point(R, t);
		oc = subtract(sq->square_center, v);
		if (fabs(oc.x) <= fabs(oc.y))
			oc.x = oc.y;
		if (fabs(oc.x)<= (double)(sq->size / 2) && t <= *distance && t > 0)
		{
			*distance = t;
			return (t);
		}
	}
	return -1;
}

double equationCylinder(ray R, t_objects *obj,double *distance)
{
	t_Cylinder *cy = ((t_Cylinder*)obj->content);
	t_vector oc = subtract(R.A, cy->cylinder_center);
	double a = scalar(R.B, R.B) - pow(scalar(R.B, cy->cylinder_norm), 2);
	double b = 2 * (scalar(oc, R.B) - (scalar(R.B, cy->cylinder_norm) * scalar(oc, cy->cylinder_norm)));
	double c = scalar(oc, oc) - pow(scalar(oc, cy->cylinder_norm), 2) - pow((double)(cy->cylinder_diametre / 2), 2);
	double des = pow(b, 2) - 4 * a * c;
	
	double t;
	if (fabs(x) > 0)
	{
		t = -y / x;
		t_vector v = line_point(R, t);
		oc = subtract(cy->cylinder_center, v);
		if (fabs(oc.x) <= fabs(oc.y))
			oc.x = oc.y;
		if (fabs(oc.x)<= (double)(cy->size / 2) && t <= *distance && t > 0)
		{
			*distance = t;
			return (t);
		}
	}
	return -1;
}