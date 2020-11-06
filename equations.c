#include "miniRT.h"

double equationSphere(ray R, t_objects *obj, double *distance)
{
	t_Sphere	*sp = ((t_Sphere*)obj->content);
	t_vector oc = subtract(R.A, sp->sphere_center);
	double a = scalar(R.B, R.B);
	double b = 2.0 * scalar(oc, R.B);
	double c = scalar(oc, oc) - ((double)(sp->sphere_diametre / 2) * (double)(sp->sphere_diametre / 2));
	double dis = (b * b) - 4 * a * c;
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
	pl->plane_norm = make_unit_vector(pl->plane_norm);
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
		if (fabs(oc.x)<= (double)(sq->size / 2) && fabs(oc.y)<= (double)(sq->size / 2) && fabs(oc.z)<= (double)(sq->size / 2)&& t <= *distance && t > 0)
		{
			*distance = t;
			return (t);
		}
	}
	return -1;
}

t_passage_cy equationCylinder(ray R, t_objects *obj,double *distance)
{
	t_Cylinder *cy;
	t_vector oc;
	double a;
	double b;
	double c;
	double des;
	double t1;
	double t2;
	double m1;
	double m2;
	t_passage_cy pass;

	pass.t = -1;
	cy = ((t_Cylinder*)obj->content);
	cy->cylinder_norm = make_unit_vector(cy->cylinder_norm);
	oc = subtract(R.A, cy->cylinder_center);
	a = scalar(R.B, R.B) - (double)(scalar(R.B, cy->cylinder_norm) \
		* scalar(R.B, cy->cylinder_norm));
	b = 2 * (scalar(R.B, oc) - (scalar(R.B, cy->cylinder_norm) \
		* scalar(oc, cy->cylinder_norm)));
	c = scalar(oc, oc) - (scalar(oc, cy->cylinder_norm) * scalar(oc, cy->cylinder_norm)) \
		- ((double)(cy->cylinder_diametre / 2) * (double)(cy->cylinder_diametre / 2));
	des = (b * b) - 4 * (a * c);
	if (des > 0)
	{
		t1 = (-b - sqrt(des)) / (2 * a);
		t2 = (-b + sqrt(des)) / (2 * a); 
		m1 = scalar(R.B, cy->cylinder_norm) * t1 + scalar(oc, cy->cylinder_norm);
		m2 = scalar(R.B, cy->cylinder_norm) * t2 + scalar(oc, cy->cylinder_norm);
		if (m1 >= (double)(-1 * cy->cylinder_height / 2) && m1 \
			<= (double)(cy->cylinder_height / 2))
			m2 = m1;
		if(t1 < t2)
			t2 = t1;
		if (t2 != 0)
		{
			if (m2 >= (double)(-1 * cy->cylinder_height / 2) && m2 <= (double)(cy->cylinder_height / 2))
			{
				if (t2 <= *distance && t2 >= 0)
				{
					pass.t = t2;
					pass.N = subtract(subtract(line_point(R, t1), cy->cylinder_center), \
							multiple(m2, cy->cylinder_norm));
					pass.N = make_unit_vector(pass.N);
				}
			}
		}
	}
	return pass;
}

double equationTriangle(ray R, t_objects *obj,double *distance)
{
	double		matrix[2][2];
	t_Triangle	*tr;
	t_vector	V1;
	t_vector	V2;
	t_vector	V;
	t_vector	P;
	double		p;
	double		q;
	double		t;
	double		det_matrix;

	tr = ((t_Triangle*)obj->content);
	V1 = subtract(tr->second_point, tr->first_point);
	V2 = subtract(tr->third_point, tr->first_point);
	V = make_unit_vector(v_product(V1, V2));
	p = scalar(R.B, V);
	q = scalar(subtract(R.A, tr->first_point), V);
	matrix[0][0] = V1.x;
	matrix[0][1] = V2.x;
	matrix[1][0] = V1.y;
	matrix[1][1] = V2.y;
	det_matrix = (double)((double)(matrix[0][0] * matrix[1][1]) - (double)(matrix[0][1] * matrix[1][0]));
	if (p != 0 && det_matrix != 0 && (double)(p * q) < 0)
	{
		t = (double)(-q / p);
		matrix[0][0] = (double)(matrix[1][1] / det_matrix);
		matrix[0][1] = (double)((matrix[0][1] * -1) / det_matrix);
		matrix[1][0] = (double)((matrix[1][0] * -1) / det_matrix);
		matrix[1][1] = (double)(matrix[0][0] / det_matrix);
		P = subtract(line_point(R, t), tr->first_point);
		p = (double)(P.x * matrix[0][0]) + (double)(P.y * matrix[0][1]);
		q = (double)(P.x * matrix[1][0]) + (double)(P.y * matrix[1][1]);  
		
		if ((p >= 0 && p < 1) && (q >= 0 && q < 1) && p + q <= 1 && t <= *distance)
		{ 
			*distance = t;
			return (t);
		}
	}
	return -1;
}

/*double equationTriangle(ray R, t_objects *obj,double *distance)
{
	t_Triangle	*tr;
	t_vector	V1;
	t_vector	V2;
	t_vector	V3;
	t_vector	V;
	t_vector	hit;
	double		x;
	double		y;
	double		d;
	double		t;

	tr = ((t_Triangle*)obj->content);
	V1 = subtract(tr->first_point, tr->second_point);
	V2 = subtract(tr->third_point, tr->second_point);
	V3 = subtract(tr->third_point, tr->first_point);
	V = make_unit_vector(v_product(V1, V2));
	d = scalar(V, V1); 
	x = scalar(R.B, V);
	y = scalar(R.A, V);
	if (x != 0 && (double)(x * y) < 0)
	{
		t = (double)(-(y + d) / x);
		hit = line_point(R, t);
		if (t <= *distance)
		{
			*distance = t;
			return (t);
		}
	}
	return -1;
}*/
