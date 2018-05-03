
#include "libft.h"

int *ft_intcpy(int *new, int *old, int size)
{
	int i;

	i = 0;
	new = (int *)malloc(sizeof(int) * size);
	while (i < size)
	{
		new[i] = old[i];
		i++;
	}
	return (new);
}
