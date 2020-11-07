#include "miniRT.h"

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int		ft_isint(char *c)
{
	int i;

	i = 0;
	while (c[i] != '\0')
	{
		if (!ft_isdigit(c[i]))
			return (0);
		i++;
	}
	return (1);
}

int		ft_isfloat(char *c)
{
	int i;

	i = 0;
	while (c[i] != '\0')
	{
		if (!ft_isdigit(c[i]) && c[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

int		ft_isvector(char *c)
{
	char **vector;
	int i;

	if (ft_nbr_words(c, ',') != 3)
		return (0);
	vector = ft_split(c, ',');
	i = 0;
	while (i < 3)
	{
		if (!ft_isnumber(vector[i]))
			return (0);
		i++;
	}
	return (1);
}
