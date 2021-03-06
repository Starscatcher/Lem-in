/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ways.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 14:58:48 by aryabenk          #+#    #+#             */
/*   Updated: 2018/05/08 14:58:49 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_ind_min_int(t_data *data, int ind)
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

int		*ft_build_way(t_data *data, int ind, int *way, int *i)
{
	int min;

	while (ind != data->indstart && ind != -1)
	{
		way = ft_int_realloc(way, *i, *i + 1);
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

void	ft_write_ways(t_ways *ways, t_room *room, int *way)
{
	t_road	*copy;
	int		size;
	t_road	*head;

	head = ways->road;
	size = 0;
	while (size != ways->len)
	{
		ways->road->name = ft_strdup(ft_find_name(room, way[size]));
		if (size + 1 != ways->len)
		{
			copy = ft_create_road(copy);
			ways->road->next = copy;
			ways->road->next->prev = ways->road;
			ways->road = ways->road->next;
		}
		size++;
	}
	ways->road = head;
}

void	ft_find_ways(t_data *data, t_room *room, t_ways *ways)
{
	int min;
	int i;
	int len;
	int *way;

	len = 1;
	while ((min = ft_ind_min_int(data, data->indend)) != -1)
	{
		i = 0;
		way = (int*)malloc(sizeof(int) * len);
		way[i++] = data->indend;
		data->length[data->indend][min] = 0;
		data->length[min][data->indend] = 0;
		way = ft_build_way(data, min, way, &i);
		if (way != NULL)
		{
			way = ft_int_reverse(way, i);
			ways->len = i;
			ft_write_ways(ways, room, way);
			ways->next = ft_create_ways(ways->next);
			ways = ways->next;
			ft_intdel(&way);
		}
	}
}
