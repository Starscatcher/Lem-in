
#include "libft.h"

int *ft_int_realloc(int *arr, int size, int newsize)
{
	int *new;
	int i;

	i = 0;
	new = (int*)malloc(sizeof(int) * newsize);
	while (i < size)
	{
		new[i] = arr[i];
		i++;
	}
	free(arr);
	return (new);
}
