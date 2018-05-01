/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_way.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 13:41:42 by aryabenk          #+#    #+#             */
/*   Updated: 2018/04/27 13:41:43 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room *ft_open_room(char *name, t_room *room)
{
	while (ft_strcmp(name, room->name))
		room = room->next;
	return (room);
}

int ft_find_index(t_room *room, char *name)
{
	int ind;

	ind = 0;
	while (ft_strcmp(room->name, room->start))
	{
		room = room->next;
		ind++;
	}
	return (ind);
}

int **ft_write_length(t_data *data, char **length, int count, int ind)
{
	int j;

	j = 0;
	while(j < data->len)
	{
		if (data->matrix[ind][j] == count)
			length[ind][j] = count;
		j++;
	}
	return (length);
}

int ft_sec_step(t_data *data, char **length, int count, t_room *room)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < data->len)
	{
		while (j < data->len)
		{
			if (length[i][j] == count)
				ft_write_length(data, length, count, j);

		}
	}
}

int **ft_length_matrix(t_data *data, t_room *room)
{
	int **length;
	int count;
	int ind;

	length = NULL;
	length = ft_make_matrix(length, data->len, -1);
	ind = ft_find_index(room, data->start);
	count = 1;
	while ()
		length = ft_write_length(data, length, count, ind);
}
