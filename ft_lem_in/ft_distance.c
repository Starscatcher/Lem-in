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

void    ft_replace_count(int ind, int count, int len, t_data *data)
{
    int y;
    int small;

    y = 0;
    while (y < len)
    {
        if (data->matrix[ind][y] == 1 && ind != data->indend)
        {
			if (!data->length[ind][y])
				small = count;
			else
            	small = ft_return_smaller(count, data->length[ind][y]);
            data->length[ind][y] = small;
            data->length[y][ind] = small;
        }
        y++;
    }
}

int *ft_search(int ind, int count, int len, t_data *data)
{
    int y;

    y = 0;
    while (y < len && ind != data->indend)
    {
        if (data->length[ind][y] == count)
        {
            ft_replace_count(y, count + 1, len, data);
            if (!data->num)
            {
                data->size++;
                data->num = (int*)malloc(sizeof(int)*data->size);
                data->num[data->size - 1] = y;
            }
            else
            {
                data->size++;
                data->num = ft_int_realloc(data->num, data->size - 1, data->size);
                data->num[data->size - 1] = y;
            }
        }
        y++;
    }
}

void	ft_length_matrix(t_data *data, int len, int count, int ind)
{
	int *arr;
	int on;
	int i;

	arr = NULL;
	on = 0;
	i = 0;
	while(!on || len)
    {
        if (!on++)
            ft_search(ind, count, data->len, data);
		ft_intdel(&arr);
        if (!arr)
        {
            len = data->size;
            arr = ft_intcpy(arr, data->num, len);
            ft_intdel(&data->num);
            data->size = 0;
            count++;
        }
	    while (i < len)
        {
            ft_search(arr[i], count, data->len, data);
            i++;
        }
        i = 0;
    }
}

void	ft_search_distance(t_data *data, t_room *room)
{
	int count;
	int ind;
	int len;

	len = 0;
	count = 1;
	data->length = ft_make_matrix(data->length, data->len, 0);
	ind = ft_find_index(room, data->start);
	data->indend = ft_find_index(room, data->end);
	ft_replace_count(ind, count, data->len, data);
	ft_length_matrix(data, len, count, ind);
}
