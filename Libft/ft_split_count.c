#include "libft.h"

int		ft_split_count(char *str, char splitter)
{
	int size;
	int i;
	char **splitted;

	size = 0;
	splitted = ft_split(str, splitter);
	while (splitted[size] != NULL)
		size++;
	//libera la matrice
	i = 0;
	while(i < size)
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	return size-1;
}
