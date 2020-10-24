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
	// R.D|NORM
	double y = scalar(oc, pl->plane_norm);
	// -OC|NORM 
	double t;
	if (x != 0)
	{
		// t = -OC|NORM / R.D|NORM
		t = -y / x;
		return (t);
	}
	return -1;
}