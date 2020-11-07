#include "miniRT.h"

int R_checker(char *line)
{
    int i;
    char	**data;

    i = ft_nbr_words(line, ' ');
    if (i == 3)
    {
	    data = ft_split_whitespaces(line);
        if (ft_isint(data[1]) && ft_isint(data[1]))
        {
            return (1);
        }
        else
            return (-3);
    }
    return (-2);
}

int A_checker(char *line)
{
    int i;
    char	**data;

    i = ft_nbr_words(line, ' ');
    
    if (i == 3)
    {
       
        data = ft_split_whitespaces(line);
        if(ft_isintensityfloat (data[1]) && ft_isvector(data[2], ft_iscolorfloat))
            return (1);
        else
            return (-5);
    }
    return (-4);
}

int c_checker(char *line)
{
    int i;
    char	**data;

    i = ft_nbr_words(line, ' ');
    if (i == 4)
    {
        data = ft_split_whitespaces(line);
        if(ft_isvector(data[1], ft_isfloat) && \
            ft_isvector(data[2], ft_isfloat) && ft_ispositiveint(data[3]))
            return (1);
        else
            return (-7);
    }
    return (-6);
}

int l_checker(char *line)
{
    int i;
    char	**data;

    i = ft_nbr_words(line, ' ');
    if (i == 4)
    {
        data = ft_split_whitespaces(line);
        if(ft_isvector(data[1], ft_isfloat) && ft_isintensityfloat(data[2]) && \
            ft_isvector(data[3] , ft_iscolorfloat))
            return (1);
        else
            return (-9);
    }
    return (-8);
}

int sp_checker(char *line)
{
    int i;
    char	**data;

    i = ft_nbr_words(line, ' ');
    if (i == 4)
    {
        data = ft_split_whitespaces(line);
        if(ft_isvector(data[1], ft_isfloat) && ft_ispositivefloat(data[2]) && \
            ft_isvector(data[3] , ft_iscolorfloat))
            return (1);
        else
            return (-11);
    }
    return (-10);
}

int pl_checker(char *line)
{
    int i;
    char	**data;

    i = ft_nbr_words(line, ' ');
    if (i == 4)
    {
        data = ft_split_whitespaces(line);
        if(ft_isvector(data[1], ft_isfloat) \
            && ft_isvector(data[2], ft_isfloat) && \
            ft_isvector(data[3] , ft_iscolorfloat))
            return (1);
        else
            return (-13);
    }
    return (-12);
}

int sq_checker(char *line)
{
    int i;
    char	**data;

    i = ft_nbr_words(line, ' ');
    if (i == 5)
    {
        data = ft_split_whitespaces(line);
        if(ft_isvector(data[1], ft_isfloat) &&\
         ft_isvector(data[2], ft_isfloat) && \
        ft_ispositivefloat(data[3]) && ft_isvector(data[4] , ft_iscolorfloat))
            return (1);
        else
            return (-15);
    }
    return (-14);
}

int cy_checker(char *line)
{
    int i;
    char	**data;

    i = ft_nbr_words(line, ' ');
    if (i == 6)
    {
        data = ft_split_whitespaces(line);
        if(ft_isvector(data[1], ft_isfloat) \
            && ft_isvector(data[2], ft_isfloat) && \
            ft_isvector(data[3] , ft_iscolorfloat) \
            && ft_ispositivefloat(data[4]) \
            && ft_ispositivefloat(data[5]))
            return (1);
        else
            return (-17);
    }
    return (-16);
}

int tr_checker(char *line)
{
    int i;
    char	**data;

    i = ft_nbr_words(line, ' ');
    if (i == 5)
    {
        data = ft_split_whitespaces(line);
        if(ft_isvector(data[1], ft_isfloat)\
         && ft_isvector(data[2], ft_isfloat) && \
        ft_isvector(data[3] , ft_isfloat) &&\
         ft_isvector(data[4] , ft_iscolorfloat))
            return (1);
        else
            return (-19);
    }
    return (-18);
}
