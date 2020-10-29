#include "miniRT.h"

t_vector light_dif_spec(t_vector newStart, t_vector N, t_vector V, t_objects *lights, t_vector color)
{
	t_vector	diffuse = (t_vector){0, 0, 0};
	t_objects	*l;
	t_Light		light;
	l = lights;
	color = multiple((double)1 / 255, color);
	while (l != NULL)
	{
		light = *(t_Light*)l->content;
		t_vector L = make_unit_vector(subtract(light.light_pos, newStart));
		t_vector R1 = make_unit_vector(subtract(multiple(2 * scalar(N, L), N), L));
		diffuse = add(diffuse, color_diffuse(multiple((double)1 / 255, color), light.light_color, L, N, light.brightness));
		diffuse = add(diffuse, color_spec(multiple((double)1 / 255, light.light_color), R1, V, light.brightness));
		l = l->next;
	}
	return (diffuse);
}

int colorCalculator(ray R, t_vector colorObj, double t, t_objects *lights, t_vector N)
{
	t_vector a_dif_spec[2];
	t_objects *l;
	t_vector color;
	t_vector newStart;
	t_vector V;

	a_dif_spec[0] = (t_vector){0, 0, 0};
	color = (t_vector){0, 0, 0};
	l = lights;
	// (t_vector){255, 255, 255}
	a_dif_spec[0] = multiple(0.5, multiple((double)1 / 255, colorObj));
	newStart = line_point(R, t);
	V = make_unit_vector(multiple(-1, R.B));
	a_dif_spec[1] = light_dif_spec(newStart, N, V, lights, colorObj);
	color = add(a_dif_spec[0], a_dif_spec[1]);
	return (rgb_maker(color_clamping(color)));
}
