#include "miniRT.h"

/*double equationSphere(ray R, t_vector sphere_center, double rayon)
{
	t_vector oc = subtract(R.A, sphere_center);
	double a = scalar(R.B, R.B);
	double b = 2.0 * scalar(oc, R.B);
	double c = scalar(oc, oc) - pow(rayon, 2);
	double dis = pow(b, 2) - 4 * a * c;

	oc = subtract(R.A, sphere_center);
	a = scalar(R.B, R.B);
	printf("dis: %.1f \n", dis);
	if (dis < 0)
	{
		return -1.0;
	}
	else
	{
		return (-b - sqrt(dis) ) / (2.0*a);
	}
}*/

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
		if (*distance > t)
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
		if (t < *distance)
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
	if (x != 0)
	{
		t = -y / x;
		oc = subtract(sq->square_center, line_point(R, t));
		if (fabs(oc.x) <= fabs(oc.y))
			oc.x = oc.y;
		if (oc.x <= sq->size / 2 && t > 0)
		{
			if (t < *distance)
			{
				*distance = t;
				return (t);
			}
		}
	}
	return -1;
}