
#include "libft.h"

void	ft_del_doubleint(int **arr, int len)
{
	if (!arr || !*arr)
		return ;
	while(len)
		ft_intdel(&arr[--len]);
	free(arr);
}
