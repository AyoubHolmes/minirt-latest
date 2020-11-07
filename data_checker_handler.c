#include "miniRT.h"

int data_checker( char **data)
{
    int i;
	i = data_id(data);
    if (i == 0)
		R_insertion(D, data);
	else if(i == 1)
		A_insertion(D, data);
	else if(i == 2){
		c_insertion(D, data);}
	else if(i == 3){
		l_insertion(D, data);}
	else if(i == 4){
		sp_insertion(D, data);}
	else if(i == 5)
		pl_insertion(D, data);
	else if(i == 6)
		sq_insertion(D, data);
	else if(i == 7)
		cy_insertion(D, data);
	else if(i == 8)
		tr_insertion(D, data);
    return (-1);
}