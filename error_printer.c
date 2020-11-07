#include "miniRT.h"

void errorPrinterHelper1(int id)
{
    if (id == -1)
        printf("not a data type \n");
    else if (id == -2)
        printf("Resolution has wrong number of values \n");
    else if (id == -3)
        printf("Resolution has a wrong entry \n");
    else if (id == -4)
        printf("Ambient has wrong number of values \n");
    else if (id == -5)
        printf("Ambient has a wrong entry \n");
    else if (id == -6)
        printf("Camera has wrong number of values \n");
    else if (id == -7)
        printf("Camera has a wrong entry \n");
    else if (id == -8)
        printf("Light has wrong number of values \n");
    else if (id == -9)
        printf("Light has a wrong entry \n");
    else if (id == -10)
        printf("Sphere has wrong number of values \n");
    else if (id == -11)
        printf("Sphere has a wrong entry \n");
}

void    errorPrinterHelper2(int id)
{
    if (id == -12)
        printf("Plane has wrong number of values\n");
    else if (id == -13)
        printf("Plane has a wrong entry\n");
    else if (id == -14)
        printf("Square has wrong number of values\n");
    else if (id == -15)
        printf("Square has a wrong entry\n");
    else if (id == -16)
        printf("Cylinder has wrong number of values\n");
     else if (id == -17)
        printf("Cylinder has a wrong entry\n");
    else if (id == -18)
        printf("Triangle has wrong number of values\n");
    else if (id == -19)
        printf("Cylinder has a wrong entry\n");
}

void errorPrinter(int id)
{
    printf("error %d:", id);
    if (id >= -11)
        errorPrinterHelper1(id);
    else
        errorPrinterHelper2(id);
}