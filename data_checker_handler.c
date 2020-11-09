#include "miniRT.h"

int data_checker(char *line)
{
    int i;
	char	**data;
	data = ft_split_whitespaces(line);
	
	i = data_id(data);
	if (i == -2)
		return (1);
    if (i == 0)
		return R_checker(line);
	else if(i == 1)
		return A_checker(line);
	else if(i == 2)
		return c_checker(line);
	else if(i == 3)
		return l_checker(line);
	else if(i == 4)
		return sp_checker(line);
	else if(i == 5)
		return pl_checker(line);
	else if(i == 6)
		return sq_checker(line);
	else if(i == 7)
		return cy_checker(line);
	else if(i == 8)
		return tr_checker(line);
    return (-1);
}