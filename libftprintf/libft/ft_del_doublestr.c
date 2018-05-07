
#include "libft.h"

void	ft_del_doublestr(char ***arr)
{
	int i;

	i = 0;
	while(*arr && (*arr)[i])
	{
		ft_strdel(&(*arr)[i]);
		i++;
	}
	free(*arr);
	*arr = NULL;
}
