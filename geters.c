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

int			inter(ray r, t_objects *p, double *distance, double *t, int color, t_objects *lights)
{
	if (p->id == 4)
		return sphereHandler(r, p, distance, t, lights, color);
	if (p->id == 5)
		return planeHandler(r, p, distance, t, lights, color);
	if (p->id == 6)
		return squareHandler(r, p, distance, t, lights, color);
	if (p->id == 7)
		return cylinderHandler(r, p, distance, t, lights, color);
	if (p->id == 8)
		return triangleHandler(r, p, distance, t, lights, color);
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

int			getPixelColor(t_objects *obj, ray r, double *distance, double *d_shadow, t_objects *lights)
{
	int			color;
	int			colorShadow;
    t_objects	*p;
	t_objects	*p2;
	double		t;

	color = 0;
	colorShadow = -1;
	*distance = INT_MAX;
	*d_shadow = INT_MAX;
	p = obj;
    while (p != NULL)
    {
        color = inter(r, p, distance, &t, color, lights);
		p2 = obj;
		while (p2 != NULL)
		{
			if (p2 != p)
			{
				colorShadow = interShadow(line_point(r, t), p2, lights, color, d_shadow);
				if (colorShadow != -1)
					color = colorShadow;
			}
			p2 = p2->next;
		}
		p = p->next;
    }
	return (color);
}