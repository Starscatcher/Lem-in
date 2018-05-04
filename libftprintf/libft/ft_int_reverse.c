
#include "libft.h"

int *ft_int_reverse(int *arr, int len)
{
	int i;

	i = 0;
	len--;
	while(i < len)
	{
		ft_swap(&arr[i], &arr[len]);
		i++;
		len--;
	}
	return (arr);
}
