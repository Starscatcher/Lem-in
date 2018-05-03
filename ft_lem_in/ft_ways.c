
#include "lem_in.h"

int 	ft_ind_min_int(t_data *data, int ind)
{
	int j;
	int min;
	int i;
	int on;

	j = 0;
	min = 0;
	on = 0;
	i = 0;
	while (j < data->len)
	{
		if (data->length[ind][j] > 0)
		{
			if (!on++ || min > data->length[ind][j])
			{
				min = data->length[ind][j];
				i = j;
			}
		}
		j++;
	}
	if (!min)
		return (-1);
	else
		return (i);
}

void	ft_zero(t_data *data, int ind)
{
	int j;

	j = 0;
	while (j < data->len)
	{
		data->length[ind][j] = 0;
		data->length[j][ind] = 0;
		j++;
	}
}

int	*ft_build_way(t_data *data, int ind, int *way, int *i)
{
	int min;

	min = 0;
	while (ind != data->indstart && ind != -1)
	{
		way = ft_int_realloc(way, *i, *i+1);
		way[*i] = ind;
		++*i;
		min = ft_ind_min_int(data, ind);
		ft_zero(data, ind);
		ind = min;
	}
	if (ind == -1)
		ft_intdel(&way);
	return (way);
}

void	ft_find_ways(t_data *data, t_room *room, t_ways *ways)
{
	t_ways *copy;
	int min;
	int i;
	int len;

	copy = ways;
	i = 0;
	len = 1;
	while ((min = ft_ind_min_int(data, data->indend)) != -1)
	{
		copy->way = (int*)malloc(sizeof(int) * len);
		copy->way[i++] = data->indend;
		data->length[data->indend][min] = 0;
		data->length[min][data->indend] = 0;
		copy->way = ft_build_way(data, min, copy->way, &i);
		if (copy->way != NULL)
		{
			for (int k = 0; k < i; ++k)
			{
				ft_printf("%d ", copy->way[k]);
			}
			ft_printf("\n");
			copy->next = ft_create_ways(copy->next);
			copy = copy->next;
		}
		i = 0;
	}
}