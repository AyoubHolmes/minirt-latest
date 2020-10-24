#include "miniRT.h"

t_vector color_diffuse(t_vector color_sphere, t_vector light_color, t_vector L, t_vector N, double brighness)
{
	t_vector color;
	double l;

	l = (l = scalar(L, N))< 0 ? 0 : l;
	color.x = color_sphere.x * light_color.x * l * brighness;
	color.y = color_sphere.y * light_color.y * l * brighness;
	color.z = color_sphere.z * light_color.z * l * brighness;
	return color;
}

t_vector color_spec(t_vector light_color, t_vector R, t_vector V, double brighness)
{
	t_vector color;
	double l;
	double alpha = 800;

	l = (l = scalar(R, V)) < 0 ? 0 : l;
	color.x = light_color.x * pow(l, alpha); 
	color.y = light_color.y * pow(l, alpha); 
	color.z = light_color.z * pow(l, alpha); 
	return color;
}

int rgb_maker(t_vector rgb)
{
	return ((int)(rgb.x * 255.99) << 16) + ((int)(rgb.y * 255.99) << 8) + (int)(rgb.z * 255.99);
}

t_vector color_clamping(t_vector color)
{
	color.x = (color.x < 1) ? color.x : 1;	
	color.x = (color.x >= 0) ? color.x : 0;
	color.y = (color.y < 1) ? color.y : 1;
	color.y = (color.y >= 0) ? color.y : 0;
	color.z = (color.z < 1) ? color.z : 1;
	color.z = (color.z >= 0) ? color.z : 0;
	return (color);
}