#include "miniRT.h"

void Vector_printer(t_vector V)
{
    printf("x: %.2f - ", V.x);
    printf("y: %.2f - ", V.y);
    printf("z: %.2f\n", V.z);
}

void Resolution_printer(t_Resolution R)
{
    printf("Resolution :\n");
    printf("x: %d\n", R.x);
    printf("y: %d\n", R.y);
    printf("------------------------ \n");
}

void Ambient_printer(t_Ambient A)
{
    printf("Ambient:\n");
    printf("precentage: %.2f\n", A.perc);
    printf("Ambient Color: ");
    Vector_printer(A.t_ambient_color);
    printf("------------------------ \n");
}

void Cam_printer(t_Cam_data c)
{
    printf("Camera: \n");
    printf("View_point: ");
    Vector_printer(c.view_point);
    printf("Cam_normal: ");
    Vector_printer(c.cam_normal);
    printf("fov: %.2f\n", c.fov);
    printf("------------------------ \n");
}
void Light_printer(t_Light L)
{
	printf("Light:\n");
	printf("Light position: ");
	Vector_printer(L.light_pos);
	printf("Brightness: %.2f\n", L.brightness);
	printf("Light Color: ");
	Vector_printer(L.light_color);
	printf("------------------------ \n");
}

void Sphere_printer(t_Sphere sp)
{
	printf("Sphere:\n");
	printf("Sphere Center: ");
	Vector_printer(sp.sphere_center);
	printf("Sphere Diametre: %.2f\n", sp.sphere_diametre);
	printf("Sphere Color: ");
	Vector_printer(sp.color_sphere);
	printf("------------------------ \n");
}

void Plane_printer(t_Plane pl)
{
	printf("Plane: \n");
	printf("Plane Center: ");
	Vector_printer(pl.plane_center);
	printf("Plane Norme: ");
	Vector_printer(pl.plane_norm);
	printf("Plane Color: ");
	Vector_printer(pl.color_plane);
	printf("------------------------ \n");
}

void Square_printer(t_Square sq)
{
	printf("Square:\n");
	printf("Square Center: ");
	Vector_printer(sq.square_center);
	printf("Square Norme: ");
	Vector_printer(sq.square_norm);
	printf("size: %.2f\n", sq.size);
	printf("Square Color: ");
	Vector_printer(sq.color_square);
	printf("------------------------ \n");
}

void Cylinder_printer(t_Cylinder cy)
{
	printf("Cylinder: \n");
	printf("Cylinder Center: ");
	Vector_printer(cy.cylinder_center);
	printf("Cylinder Norme: ");
	Vector_printer(cy.cylinder_norm);
	printf("Cylinder Color: ");
	Vector_printer(cy.cylinder_color);
	printf("Cylinder Diametre: %.2f\n", cy.cylinder_diametre);
	printf("Cylinder Height: %.2f\n", cy.cylinder_height);
	printf("------------------------ \n");
}

void Triangle_printer(t_Triangle tr)
{
    printf("Triangle:\n");
    printf("First Point: ");
    Vector_printer(tr.first_point);
    printf("Second Point: ");
    Vector_printer(tr.second_point);
    printf("Third Point: ");
    Vector_printer(tr.third_point);
    printf("------------------------ \n");
}
