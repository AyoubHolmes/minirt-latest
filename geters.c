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

int			interShadowUpgraded(t_p_shadow  t_shadow, t_objects *p, t_objects *lights, double *d_shadow)
{
	double t = -1;
	t_vector shadowColor;
	double A;
	double B;
	t_objects *l;
	ray r;

	r.A = t_shadow.newStart;
    l = lights;
	while (l != NULL)
	{
		r.B = make_unit_vector(subtract((*(t_Light*)l->content).light_pos, t_shadow.newStart));
		if (p->id == 4)
		{
			A = squared_length(subtract((*(t_Light*)l->content).light_pos, t_shadow.object_position));
			B = squared_length(subtract((*(t_Sphere*)p->content).sphere_center, t_shadow.object_position));
			t = equationSphere(r, p, d_shadow);
		}
		if (p->id == 5)
		{
			A = squared_length(subtract((*(t_Light*)l->content).light_pos, t_shadow.object_position));
			B = squared_length(subtract((*(t_Plane*)p->content).plane_center, t_shadow.object_position));
			t = equationPlane(r, p, d_shadow);
		}
		if (p->id == 6)
		{
			A = squared_length(subtract((*(t_Light*)l->content).light_pos, t_shadow.object_position));
			B = squared_length(subtract((*(t_Square*)p->content).square_center, t_shadow.object_position));
			t = equationSquare(r, p, d_shadow);
		}
		if (p->id == 7)
		{
			A = squared_length(subtract((*(t_Light*)l->content).light_pos, t_shadow.object_position));
			B = squared_length(subtract((*(t_Cylinder*)p->content).cylinder_center, t_shadow.object_position));
			t = equationCylinder(r, p, d_shadow).t;
		}
		if (t > 0)
			break;
		l = l->next;
	}
	if (t >= 0 && t <= *d_shadow && A > B)
	{
		shadowColor = multiple(0.5, multiple((double)1 / 255, t_shadow.color_shadow));
		*d_shadow = t;
        return (rgb_maker(color_clamping(shadowColor)));
	}
	return (-1);
}


int			getPixelColor(t_objects *obj, ray r, double *distance, double *d_shadow, t_objects *lights)
{
	int			color;
	int			colorShadow;
    t_objects	*p;
	t_objects	*p2;
	double		t;
	t_p_shadow	t_shadow;

	color = 0;
	colorShadow = -1;
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
				colorShadow = interShadowUpgraded(t_shadow, p2, lights, d_shadow);
				//colorShadow = interShadow(line_point(r, t), p2, lights, color, d_shadow);
				if (colorShadow != -1)
					color = colorShadow;
			}
			p2 = p2->next;
		}
		p = p->next;
    }
	return (color);
}