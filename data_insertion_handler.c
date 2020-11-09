#include "miniRT.h"

int		data_id(char **data)
{
	if(data[0][0] == '#')
		return (-2);
	if(data[0][0] == 'R' && ft_strlen(data[0]) == 1)
		return (0);
	else if(data[0][0] == 'A' && ft_strlen(data[0])== 1)
		return (1);
    else if(data[0][0] == 'c' && ft_strlen(data[0]) == 1)
        return (2);
    else if(data[0][0] == 'l' && ft_strlen(data[0]) == 1)
        return (3);
    else if(data[0][0] == 's' && data[0][1] == 'p' && ft_strlen(data[0]) == 2)
        return (4);
    else if(data[0][0] == 'p' && data[0][1] == 'l' && ft_strlen(data[0]) == 2)
        return (5);
    else if(data[0][0] == 's' && data[0][1] == 'q' && ft_strlen(data[0]) == 2)
        return (6);
    else if(data[0][0] == 'c' && data[0][1] == 'y' && ft_strlen(data[0]) == 2)
        return (7);
    else if(data[0][0] == 't' && data[0][1] == 'r' && ft_strlen(data[0]) == 2)
        return (8);
    return (-1);
}

void	data_insertion(t_data *D, char **data)
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
}