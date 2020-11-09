#include "miniRT.h"

void errorPrinterHelper1(int id)
{
    if (id == -1)
        ft_putstr_fd("not a data type \n", 2);
    else if (id == -2)
        ft_putstr_fd("Resolution has wrong number of values \n", 2);
    else if (id == -3)
        ft_putstr_fd("Resolution has a wrong entry \n", 2);
    else if (id == -4)
        ft_putstr_fd("Ambient has wrong number of values \n", 2);
    else if (id == -5)
        ft_putstr_fd("Ambient has a wrong entry \n", 2);
    else if (id == -6)
        ft_putstr_fd("Camera has wrong number of values \n", 2);
    else if (id == -7)
        ft_putstr_fd("Camera has a wrong entry \n", 2);
    else if (id == -8)
        ft_putstr_fd("Light has wrong number of values \n", 2);
    else if (id == -9)
        ft_putstr_fd("Light has a wrong entry \n", 2);
    else if (id == -10)
        ft_putstr_fd("Sphere has wrong number of values \n", 2);
    else if (id == -11)
        ft_putstr_fd("Sphere has a wrong entry \n", 2);
}

void    errorPrinterHelper2(int id)
{
    if (id == -12)
        ft_putstr_fd("Plane has wrong number of values\n", 2);
    else if (id == -13)
        ft_putstr_fd("Plane has a wrong entry\n", 2);
    else if (id == -14)
        ft_putstr_fd("Square has wrong number of values\n", 2);
    else if (id == -15)
        ft_putstr_fd("Square has a wrong entry\n", 2);
    else if (id == -16)
        ft_putstr_fd("Cylinder has wrong number of values\n", 2);
     else if (id == -17)
        ft_putstr_fd("Cylinder has a wrong entry\n", 2);
    else if (id == -18)
        ft_putstr_fd("Triangle has wrong number of values\n", 2);
    else if (id == -19)
        ft_putstr_fd("Cylinder has a wrong entry\n", 2);
}

void errorPrinter(t_err err)
{
    ft_putstr_fd("ERROR:", 2);
    if (err.isChecked >= -11)
        errorPrinterHelper1(err.isChecked);
    else
        errorPrinterHelper2(err.isChecked);
}