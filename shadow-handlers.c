#include "miniRT.h"

int sphereShadowHandler(t_vector newStart, t_objects *p, t_objects *lights, int color, double *d_shadow)
{
    double t;
    t_objects	*l;
    ray r;
    t_vector shadowColor;

    r.A= newStart;
    l = lights;
    while (l != NULL)
    {
         r.B = substract((*(t_Light*)l->content).light_pos, newStart);
        t = equationSphere(r, p, d_shadow);
        if (t > 0)
        {
            shadowColor = multiple(0.5, (t_vector){0, 0, 0});
            return (rgb_maker(color_clamping(shadowColor)));
        }
        l = l->next;
    }
    return (color);
}

int planeShadowHandler(t_vector newStart, t_objects *p, t_objects *lights, int color, double *d_shadow)
{
    double t;
    t_objects	*l;
    ray r;
    t_vector shadowColor;

    r.A= newStart;
    l = lights;
    while (l != NULL)
    {
        r.B = substract((*(t_Light*)l->content).light_pos, newStart);
        t = equationPlane(r, p, d_shadow);
        if (t > 0)
        {
            shadowColor = multiple(0.2, multiple((double)1 / 255, (*(t_Plane*)p->content).color_plane));
            return (rgb_maker(color_clamping(shadowColor)));
        }
        l = l->next;
    }
    return (color);
}

int squareShadowHandler(t_vector newStart, t_objects *p, t_objects *lights, int color, double *d_shadow)
{
    double t;
    t_objects	*l;
    ray r;
    t_vector shadowColor;

    r.A= newStart;
    l = lights;
    while (l != NULL)
    {
        r.B = substract((*(t_Light*)l->content).light_pos, newStart);
        t = equationSquare(r, p, d_shadow);
        if (t > 0)
        {
            shadowColor = multiple(0.5, (t_vector){0.5, 0.5, 0.5});
            return (rgb_maker(color_clamping(shadowColor)));
        }
        l = l->next;
    }
    return (color);
}

int cylinderShadowHandler(t_vector newStart, t_objects *p,  t_objects *lights, int color, double *d_shadow)
{
    ray r;
	t_passage_cy pass;
    t_vector shadowColor;
    t_objects    *l;

    r.A = newStart;
    l = lights;
    while (l != NULL)
    {
        r.B = substract((*(t_Light*)l->content).light_pos, newStart);
        pass = equationCylinder(r, p, d_shadow);
        if (pass.t >= 0)
        {
            shadowColor = multiple(0.5, (t_vector){0.5, 0.5, 0.5});
            return (rgb_maker(color_clamping(shadowColor)));
            
        }
        l = l->next;
    }
    return (color);
}
