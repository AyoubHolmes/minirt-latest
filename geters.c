#include "miniRT.h"

t_objects *getLigths(t_objects *obj)
{
	t_objects	*p;
	t_objects	*q;
	t_objects	*lst;

	p = obj;
	lst = NULL;
	if (!(q = (t_objects*)malloc(sizeof(t_objects))))
		return (0);
	while (p != NULL)
	{
		if (p->id == 3)
		{
			q->content = p->content;
			q->id = 3;
			q->next = NULL;
			ft_lstadd_back(&lst, q);
		}
		p = p->next;
	}
	return (lst);
}

int			inter(ray r, t_objects *p, double *distance, double *t, int color, t_objects *lights, t_p_shadow *t_shadow)
{
	if (p->id == 4)
		return sphereHandler(r, p, distance, t, lights, color, t_shadow);
	if (p->id == 5)
		return planeHandler(r, p, distance, t, lights, color, t_shadow);
	if (p->id == 6)
		return squareHandler(r, p, distance, t, lights, color, t_shadow);
	if (p->id == 7)
		return cylinderHandler(r, p, distance, t, lights, color, t_shadow);
	if (p->id == 8)
		return triangleHandler(r, p, distance, t, lights, color, t_shadow);
	return color;
}

int interShadow(t_vector newStart, t_objects *p, t_objects *lights, int color, double *d_shadow)
{
	if (p->id == 4)
		return sphereShadowHandler(newStart, p, lights, color, d_shadow);
	if (p->id == 5)
		return planeShadowHandler(newStart, p, lights, color, d_shadow);
	if (p->id == 6)
		return squareShadowHandler(newStart, p, lights, color, d_shadow);
	if (p->id == 7)
		return cylinderShadowHandler(newStart, p, lights, color, d_shadow);
	return (-1);
}

int			shadowHandler(t_vector A, t_vector B, t_vector C)
{
	double a;
	double b;

	a = squared_length(substract(B, A));
	b = squared_length(substract(C, A));
	if (a > b)
		return (1);
	return (0);
}

t_vector approCorrector(t_vector v)
{
	return (add(v, (t_vector){1e-4f,1e-4f,1e-4f}));
}

int			interShadowUpgraded(t_p_shadow  t_shadow, t_objects *p, t_objects *lights, double *d_shadow)
{
	double t = -1;
	t_vector shadowColor;
	double A;
	double B;
	t_objects *l;
	ray r;

	r.A = approCorrector(t_shadow.newStart);
    l = lights;
	while (l != NULL)
	{
		r.B = make_unit_vector(\
			substract((*(t_Light*)l->content).light_pos, t_shadow.newStart));
		if (p->id == 4)
		{
			A = length(substract((*(t_Light*)l->content).light_pos, t_shadow.newStart));
			B = length(substract((*(t_Sphere*)p->content).sphere_center, t_shadow.newStart));
			t = equationSphere(r, p, d_shadow);
			if (t >= 0 && t <= *d_shadow && A > B)
			{
				shadowColor = multiple(0.5, multiple((double)1 / 255, t_shadow.color_shadow));
				*d_shadow = t;
				return (rgb_maker(color_clamping(shadowColor)));
			}
		}
		if (p->id == 5)
		{
			A = length(substract((*(t_Light*)l->content).light_pos, t_shadow.newStart));
			B = length(substract((*(t_Plane*)p->content).plane_center, t_shadow.newStart));
			t = equationPlane(r, p, d_shadow);
			if (t >= 0 && t <= *d_shadow && A > B)
			{
				shadowColor = multiple(0.5, multiple((double)1 / 255, t_shadow.color_shadow));
				*d_shadow = t;
				return (rgb_maker(color_clamping(shadowColor)));
			}
		}
		if (p->id == 6)
		{
			A = length(substract((*(t_Light*)l->content).light_pos, t_shadow.newStart));
			B = length(substract((*(t_Square*)p->content).square_center, t_shadow.newStart));
			t = equationSquare(r, p, d_shadow);
			if (t >= 0 && t <= *d_shadow && A > B)
			{
				shadowColor = multiple(0.5, multiple((double)1 / 255, t_shadow.color_shadow));
				*d_shadow = t;
				return (rgb_maker(color_clamping(shadowColor)));
			}
		}
		if (p->id == 7)
		{
			A = length(substract((*(t_Light*)l->content).light_pos, t_shadow.newStart));
			B = length(substract((*(t_Cylinder*)p->content).cylinder_center, t_shadow.newStart));
			t = equationCylinder(r, p, d_shadow).t;
			if (t >= 0 && t <= *d_shadow && A > B)
			{
				shadowColor = multiple(0.5, multiple((double)1 / 255, t_shadow.color_shadow));
				*d_shadow = t;
				return (rgb_maker(color_clamping(shadowColor)));
			}
		}
		l = l->next;
	}
	return (-1);
}

int			shadow_cheker(t_vector a, t_vector b, t_vector c)
{
	double A;
	double B;


	A = length(substract(b, a));
	B = length(substract(c, a));
	return (A > B);
}

double		interShadowFuncs(t_p_shadow  *t_shadow, t_objects *p, t_objects *lights, double *d_shadow)
{
	double t;
	t_objects *l;
	ray r;

	t = -1;
	r.A = approCorrector(t_shadow->newStart);
	l = lights;
	while (l != NULL)
	{
		t_shadow->light_pos = (*(t_Light*)l->content).light_pos;
		r.B = make_unit_vector(\
			substract(t_shadow->light_pos, t_shadow->newStart));
		if (p->id == 4)
			t = equationSphere(r, p, d_shadow);
		if (p->id == 5)
			t = equationPlane(r, p, d_shadow);
		if (p->id == 6)
			t = equationSquare(r, p, d_shadow);
		if (p->id == 7)
			t = equationCylinder(r, p, d_shadow).t;
		if (p->id == 8)
			t = equationTriangle(r, p, d_shadow);
		if (t >= 0 && t <= *d_shadow )
		{
			t_shadow->object_pos = line_point(r, t);
			return (t);
		}
		l = l->next;
	}
	return (-1);
}

int			getPixelColor(t_objects *obj, ray r, double *distance, double *d_shadow, t_objects *lights)
{
	int			color;
	t_vector	colorShadow;
    t_objects	*p;
	t_objects	*p2;
	double		t;
	double		t2;
	t_p_shadow	t_shadow;

	color = 0;
	*distance = INT_MAX;
	*d_shadow = INT_MAX;
	p = obj;
    while (p != NULL)
    {
        color = inter(r, p, distance, &t, color, lights, &t_shadow);
		p2 = obj;
		while (p2 != NULL)
		{
			if (p2 != p)
			{
				t2 = interShadowFuncs(&t_shadow, p2, lights, d_shadow);
				if (t2 > 0)
				{
					if (shadow_cheker(t_shadow.newStart, t_shadow.light_pos, t_shadow.object_pos))
					{
						colorShadow = multiple(0.5, multiple((double)1 / 255, t_shadow.color_shadow));
						color = (rgb_maker(color_clamping(colorShadow)));
					}
				}
			}
			p2 = p2->next;
		}
		p = p->next;
    }
	return (color);
}
