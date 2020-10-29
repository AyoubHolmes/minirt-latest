#include "miniRT.h"

void vectorPrinter (t_vector V)
{
    printf("x: %f\n", V.x);
    printf("y: %f\n", V.y);
    printf("z: %f\n", V.z);

}

void resolutionPrinter(t_Resolution res)
{
	printf("------------ Resolution --------\n");
    printf("-> x: %d\n", res.x);
	printf("-> y: %d\n", res.y);
	printf("-> done: %d\n", res.done);
}

void ambientPrinter (t_Ambient ab)
{
    printf("------------ Ambient --------\n");
    printf("-> Ambient Color:\n");
    vectorPrinter(ab.t_ambient_color);
    printf("-> perc: %.1f\n", ab.perc);
}

void cameraPrinter (t_Cam_data *cam)
{
    printf("------------ Camera --------\n");
    printf("-> view_point:\n");
    vectorPrinter(cam->view_point);
    printf("-> fov: %.1f\n", cam->fov);
    printf("-> cam_normal:\n");
    vectorPrinter(cam->cam_normal);
}

void lightPrinter (t_Light *light)
{
    printf("------------ Light --------\n");
    printf("-> light_pos:\n");
    vectorPrinter(light->light_pos);
    printf("-> brightness: %.1f\n", light->brightness);
    printf("-> light_color:\n");
    vectorPrinter(light->light_color);
}

void spherePrinter (t_Sphere *S)
{
    printf("------------ Sphere --------\n");
    printf("-> sphere center:\n");
    vectorPrinter(S->sphere_center);
    printf("-> sphere diametre: %.1f\n", S->sphere_diametre);
    printf("-> sphere color:\n");
    vectorPrinter(S->color_sphere);
}

void planePrinter (t_Plane *P)
{
    printf("------------ Plane --------\n");
    printf("-> plane center:\n");
    vectorPrinter(P->plane_center);
    printf("-> plane norm:\n");
    vectorPrinter(P->plane_norm);
    printf("-> plane color:\n");
    vectorPrinter(P->color_plane);    
}

void squarePrinter(t_Square *Sq)
{
    printf("------------ Square --------\n");
    printf("-> square center:\n");
    vectorPrinter(Sq->square_center);
    printf("-> square norm:\n");
    vectorPrinter(Sq->square_norm);
    printf("->square size: %f\n", Sq->size);
    printf("-> square color:\n");
    vectorPrinter(Sq->color_square);  
}

void cylinderPrinter(t_Cylinder *cy)
{
    printf("------------ Cylinder --------\n");
    printf("-> cylinder center:\n");
    vectorPrinter(cy->cylinder_center);
    printf("-> cylinder norm:\n");
    vectorPrinter(cy->cylinder_norm);
    printf("->cylinder size: %f\n", (double)(cy->cylinder_diametre / 2));
    printf("-> cylinder color:\n");
    vectorPrinter(cy->cylinder_color); 
    printf("-> cylinder height: %f\n", cy->cylinder_height);
}

void trianglePrinter(t_Triangle *tr)
{
    printf("------------ Triangle --------\n");
    printf("-> first point:\n");
    vectorPrinter(tr->first_point);
    printf("-> second point:\n");
    vectorPrinter(tr->second_point);
    printf("-> third point:\n");
    vectorPrinter(tr->third_point);
    printf("-> triangle color:\n");
    vectorPrinter(tr->triangle_color);
}


void objectsDebugger(t_data d)
{
    t_objects *p;

    p = d.obj;
	resolutionPrinter(d.R);
	ambientPrinter(d.A);
    while (p != NULL)
    {
		if (p->id == 2)
            cameraPrinter((t_Cam_data*)(p->content));
        else if (p->id == 3)
            lightPrinter((t_Light*)(p->content));
		else if (p->id == 4)
            spherePrinter((t_Sphere*)(p->content));
        else if (p->id == 5)
            planePrinter((t_Plane*)(p->content));
        else if (p->id == 6)
            squarePrinter((t_Square*)(p->content));
        else if (p->id == 7)
            cylinderPrinter((t_Cylinder*)(p->content));
        else if (p->id == 8)
            trianglePrinter((t_Triangle*)(p->content));
        p = p->next;
    }

}
