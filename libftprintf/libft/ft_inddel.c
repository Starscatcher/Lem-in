
#include "libft.h"

void	ft_intdel(int **arr)
{
	if (arr)
	{
		free(*arr);
		*arr = NULL;
	}
}
