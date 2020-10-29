#include "miniRT.h"

void R_insertion(t_data *D, char **data)
{
    D->R.x = atoi(data[1]);
    D->R.y = atoi(data[2]);
    D->R.done = 1;
}

void A_insertion(t_data *D, char **data)
{
    char **ambient_color;
    D->A.perc = strtof(data[1], NULL);
    ambient_color = ft_split(data[2], ',');
    D->A.t_ambient_color = (t_vector){ strtof(ambient_color[0], NULL)\
        , strtof(ambient_color[1], NULL), strtof(ambient_color[2], NULL) };
}

void c_insertion(t_data *D, char **data)
{
    char **view_point;
    char **cam_normal;
    t_objects *p;

    view_point = ft_split(data[1], ',');
    cam_normal = ft_split(data[2], ',');
	if (!D->obj)
    {
		if (!(D->obj = (t_objects*)malloc(sizeof(t_objects))))
			return ;
		D->obj = camInitializer(view_point, cam_normal, data[3]);
    }
    else
    {
        p = D->obj;
        while (p->next != NULL)
            p = p->next;
		if (!(p->next = (t_objects*)malloc(sizeof(t_objects))))
			return ;
		p->next = camInitializer(view_point, cam_normal, data[3]);
    }
}


void l_insertion(t_data *D, char **data)
{
    char		**light_pos;
    char		**light_color;
    t_objects	*p;

    light_pos = ft_split(data[1], ',');
    light_color = ft_split(data[3], ',');
    if (!D->obj)
    {
		if (!(D->obj = (t_objects*)malloc(sizeof(t_objects))))
			return ;
        if(!(D->obj->content = (t_Light*)malloc(sizeof(t_Light))))
            return ;
        D->obj = ligthInitializer(light_pos, light_color, data[2]);
    }
    else
    {
        p = D->obj;
        while (p->next != NULL)
            p = p->next;
		if (!(p->next = (t_objects*)malloc(sizeof(t_objects))))
			return ;
        if(!(p->next->content = (t_Light*)malloc(sizeof(t_Light))))
            return ;
        p->next = ligthInitializer(light_pos, light_color, data[2]);
    }
}

void sp_insertion(t_data *D, char **data)
{
    char		**sphere_center;
    char		**color_sphere;
    t_objects	*p;

    sphere_center = ft_split(data[1], ',');
    color_sphere = ft_split(data[3], ',');
    if (!D->obj)
    {
        
		if (!(D->obj = (t_objects*)malloc(sizeof(t_objects))))
			return ;
        if(!(D->obj->content = (t_Sphere*)malloc(sizeof(t_Sphere))))
            return ;
        D->obj= sphereInitialize(sphere_center, color_sphere, data[2]);
    }
    else
    {
        p = D->obj;
        while (p->next != NULL)
            p = p->next;
		if (!(p->next = (t_objects*)malloc(sizeof(t_objects))))
			return ;
        if(!(p->next->content = (t_Sphere*)malloc(sizeof(t_Sphere))))
            return ;
        p->next = sphereInitialize(sphere_center, color_sphere, data[2]);
    }
}

void pl_insertion(t_data *D, char **data)
{
	char **plane_center;
	char **plane_norm;
	char **color_plane;
	t_objects *p;

	plane_center = ft_split(data[1], ',');
	plane_norm = ft_split(data[2], ',');
	color_plane = ft_split(data[3], ',');
    if (!D->obj)
    {
        if(!(D->obj = (t_objects*)malloc(sizeof(t_objects))))
            return ;
		if(!(D->obj->content = (t_Plane*)malloc(sizeof(t_Plane))))
            return ;
        D->obj->content = planeInitialize(plane_center, plane_norm, color_plane);
		D->obj->id = 5;
        D->obj->next = NULL;
    }
    else
    {
        p = D->obj;
        while (p->next != NULL)
            p = p->next;
        if(!(p->next = (t_objects*)malloc(sizeof(t_objects))))
            return ;
		if(!(p->next->content = (t_Plane*)malloc(sizeof(t_Plane))))
            return ;
        p->next->content = planeInitialize(plane_center, plane_norm, color_plane);
		p->next->id = 5;
        p->next->next = NULL;
    }
}
 
void sq_insertion(t_data *D, char **data)
{
	char **square_center;
	char **square_norm;
	char **color_square;
    char *size;
	t_objects *p;

	square_center = ft_split(data[1], ',');
	square_norm = ft_split(data[2], ',');
    size = data[3];
	color_square = ft_split(data[4], ',');
    if (!D->obj)
    {
        if(!(D->obj = (t_objects*)malloc(sizeof(t_objects))))
            return ;
		if(!(D->obj->content = (t_Square*)malloc(sizeof(t_Square))))
            return ;
        D->obj->content = squareInitialize(square_center, square_norm, color_square, size);
		D->obj->id = 6;
        D->obj->next = NULL;
    }
    else
    {
        p = D->obj;
        while (p->next != NULL)
            p = p->next;
        if(!(p->next = (t_objects*)malloc(sizeof(t_objects))))
            return ;
		if(!(p->next->content = (t_Square*)malloc(sizeof(t_Square))))
            return ;
        p->next->content = squareInitialize(square_center, square_norm, color_square, size);
		p->next->id = 6;
        p->next->next = NULL;
    }
}

void cy_insertion(t_data *D, char **data)
{
	char **cylinder_center;
	char **cylinder_norm;
	char **cylinder_color;
    char *cylinder_diametre;
    char *cylinder_height;
	t_objects *p;

	cylinder_center = ft_split(data[1], ',');
	cylinder_norm = ft_split(data[2], ',');
    cylinder_diametre = data[4];
    cylinder_height = data[5];
	cylinder_color = ft_split(data[3], ',');
    if (!D->obj)
    {
        if(!(D->obj = (t_objects*)malloc(sizeof(t_objects))))
            return ;
		if(!(D->obj->content = (t_Cylinder*)malloc(sizeof(t_Cylinder))))
            return ;
        D->obj->content = cylinderInitialize(cylinder_center, cylinder_norm, cylinder_color, cylinder_diametre, cylinder_height);
		D->obj->id = 7;
        D->obj->next = NULL;
    }
    else
    {
        p = D->obj;
        while (p->next != NULL)
            p = p->next;
        if(!(p->next = (t_objects*)malloc(sizeof(t_objects))))
            return ;
		if(!(p->next->content = (t_Cylinder*)malloc(sizeof(t_Cylinder))))
            return ;
        p->next->content = cylinderInitialize(cylinder_center, cylinder_norm, cylinder_color, cylinder_diametre, cylinder_height);
		p->next->id = 7;
        p->next->next = NULL;
    }
}

void tr_insertion(t_data *D, char **data)
{
	char **first_point;
	char **second_point;
	char **third_point;
    char **triangle_color;
	t_objects *p;

	first_point = ft_split(data[1], ',');
	second_point = ft_split(data[2], ',');
	third_point = ft_split(data[3], ',');
    triangle_color = ft_split(data[4], ',');
    if (!D->obj)
    {
        if(!(D->obj = (t_objects*)malloc(sizeof(t_objects))))
            return ;
		if(!(D->obj->content = (t_Cylinder*)malloc(sizeof(t_Cylinder))))
            return ;
        D->obj->content = triangleInitialize(first_point, second_point, third_point, triangle_color);
		D->obj->id = 8;
        D->obj->next = NULL;
    }
    else
    {
        p = D->obj;
        while (p->next != NULL)
            p = p->next;
        if(!(p->next = (t_objects*)malloc(sizeof(t_objects))))
            return ;
		if(!(p->next->content = (t_Cylinder*)malloc(sizeof(t_Cylinder))))
            return ;
        p->next->content = triangleInitialize(first_point, second_point, third_point, triangle_color);
		p->next->id = 8;
        p->next->next = NULL;
    }
}