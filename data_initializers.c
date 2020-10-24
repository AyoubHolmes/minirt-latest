#include "miniRT.h"

t_objects *ligthInitializer(char **lp, char **lc, char *brightness)
{
    t_Light *light;
    t_objects *obj;

	if(!(light = (t_Light*)malloc(sizeof(t_Light))))
		return (0);
    if(!(obj = (t_objects*)malloc(sizeof(t_objects))))
		return (0);
	light->light_pos = initialize_vector(atof(lp[0]), atof(lp[1]), atof(lp[2]));
	light->light_color = initialize_vector(atof(lc[0]), atof(lc[1]), atof(lc[2]));
	light->brightness = strtof(brightness, NULL);
    obj->id = 3;
    obj->content = light;
    obj->next = NULL;
	return (obj);
}

t_objects *camInitializer(char **vp, char **cn, char *fov)
{
    t_Cam_data *cam;
    t_objects *obj;

	if(!(cam = (t_Cam_data*)malloc(sizeof(t_Cam_data))))
		return (0);
    if(!(obj = (t_objects*)malloc(sizeof(t_objects))))
		return (0);
	cam->view_point = initialize_vector(atof(vp[0]), atof(vp[1]), atof(vp[2]));
	cam->cam_normal = initialize_vector(atof(cn[0]), atof(cn[1]), atof(cn[2]));
	cam->fov = strtof(fov, NULL);
    obj->id = 2;
    obj->content = cam;
    obj->next = NULL;
	return (obj);
}

t_objects *sphereInitialize(char **sc, char **color_sphere, char *sphere_diametre)
{
	t_objects   *obj;
    t_Sphere    *sphere;

	if(!(sphere = (t_Sphere*)malloc(sizeof(t_Sphere))))
		return (0);
    if (!(obj = (t_objects*)malloc(sizeof(t_objects))))
			return (0);
	sphere->sphere_center = initialize_vector(atof(sc[0]), atof(sc[1]), atof(sc[2]));
	sphere->sphere_diametre = strtof(sphere_diametre, NULL);
	sphere->color_sphere = initialize_vector(atof(color_sphere[0]), atof(color_sphere[1]), atof(color_sphere[2]));
    obj->id = 4;
    obj->content = sphere;
    obj->next = NULL;
	return (obj);
}

t_Plane *planeInitialize(char **plane_center, char **plane_norm, char **color_plane) 
{
	t_Plane *plane;

	if(!(plane = (t_Plane*)malloc(sizeof(t_Plane))))
		return (0);
	plane->plane_center = (t_vector)
	{
		strtof(plane_center[0], NULL),
		strtof(plane_center[1], NULL),
		strtof(plane_center[2], NULL)
	};
	plane->plane_norm = (t_vector)
	{
		strtof(plane_norm[0], NULL),
		strtof(plane_norm[1], NULL),
		strtof(plane_norm[2], NULL)
	};
	plane->color_plane = (t_vector)
	{
		strtof(color_plane[0], NULL),
		strtof(color_plane[1], NULL),
		strtof(color_plane[2], NULL)
	};
	return (plane);
}