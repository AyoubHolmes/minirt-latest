#include "miniRT.h"

int sphereShadowHandler(t_vector newStart, t_objects *p, t_objects *lights, int color)
{
    double t;
    double distance;
    t_objects	*l;
    ray r;
    t_vector shadowColor;

    distance = INT_MAX;
    r.A= newStart;
    l = lights;
    while (l != NULL)
    {
         r.B = subtract((*(t_Light*)l->content).light_pos, newStart);
        t = equationSphere(r, p, &distance);
        if (t > 0)
        {
            shadowColor = multiple(0.5, multiple((double)1 / 255, (*(t_Sphere*)p->content).color_sphere));
            return (rgb_maker(color_clamping(shadowColor)));
        }
        l = l->next;
    }
    return (color);
}

int planeShadowHandler(t_vector newStart, t_objects *p, t_objects *lights, int color)
{
    double t;
    double distance;
    t_objects	*l;
    ray r;
    t_vector shadowColor;

    distance = INT_MAX;
    r.A= newStart;
    l = lights;
    while (l != NULL)
    {
        r.B = subtract((*(t_Light*)l->content).light_pos, newStart);
        t = equationPlane(r, p, &distance);
        printf("t ==> %f\n", t);
        if (t > 0)
        {
            shadowColor = multiple(0.5, multiple((double)1 / 255, (*(t_Plane*)p->content).color_plane));
            return (rgb_maker(color_clamping(shadowColor)));
        }
        l = l->next;
    }
    return (color);
}

int squareShadowHandler(t_vector newStart, t_objects *p, t_objects *lights, int color)
{
    double t;
    double distance;
    t_objects	*l;
    ray r;
    t_vector shadowColor;

    distance = INT_MAX;
    r.A= newStart;
    l = lights;
    while (l != NULL)
    {
        r.B = subtract(newStart, (*(t_Light*)l->content).light_pos);
        t = equationSquare(r, p, &distance);
        if (t > 0)
        {
            //multiple((double)1 / 255, (*(t_Sphere*)p->content).color_sphere)
            shadowColor = multiple(0.5, (t_vector){0.5, 0.5, 0.5});
            return (rgb_maker(color_clamping(shadowColor)));
        }
        l = l->next;
    }
    return (color);
}

int cylinderShadowHandler(t_vector newStart, t_objects *p,  t_objects *lights, int color)
{
    ray r;
	t_passage_cy pass;
    t_vector shadowColor;
    t_objects    *l;
    double distance;

    r.A = newStart;
    l = lights;
    distance = INT_MAX;
    while (l != NULL)
    {
        r.B = subtract((*(t_Light*)l->content).light_pos, newStart);
        pass = equationCylinder(r, p, &distance);
        if (pass.t >= 0)
        {
            shadowColor = multiple(0.5, (t_vector){0.5, 0.5, 0.5});
            return (rgb_maker(color_clamping(shadowColor)));
            
        }
        l = l->next;
    }
    return (color);
}
