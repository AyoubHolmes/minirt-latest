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
    {
		*t = equationSphere(r, p, distance);
		if (*t > 0)
			return colorSphere(r, *(t_Sphere*)p->content, *t, lights);
    }
	if (p->id == 5)
    {
		*t = equationPlane(r, p, distance);
		if (*t > 0)
			return colorPlane(r, *(t_Plane*)p->content, *t);
    }
	return color;
}

int			getPixelColor(t_objects *obj, ray r, double *distance, t_objects *lights)
{
	int			color;
    t_objects	*p;
	double		t;

	color = 0;
	*distance = INT_MAX;
	p = obj;
    while (p != NULL)
    {
        color = inter(r, p, distance, &t, color, lights);
		p = p->next;
    }
	return (color);
}