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
	while (ft_strcmp(room->name, name))
	{
		room = room->next;
		ind++;
	}
	return (ind);
}

int ft_return_small(int count, int a)
{
    if (!a)
        return (count);
    else if (count < a)
        return (count);
    else
        return(a);
}

void    ft_replace_count(int ind, int count, int len, t_data *data, int end)
{
    int y;
    int small;

    y = 0;
    while (y < len)
    {
        if (data->matrix[ind][y] == 1 && ind != end)
        {
            small = ft_return_small(count, data->length[ind][y]);
            data->length[ind][y] = small;
            data->length[y][ind] = small;
        }
        y++;
    }
}

int *ft_search(int ind, int count, int len, t_data *data, int end)
{
    int y;

    y = 0;
    while (y < len && ind != end)
    {
        if (data->length[ind][y] == count)
        {
            ft_replace_count(y, count + 1, len, data, end);
            if (!data->num)
            {
                data->size++;
                data->num = (int *) malloc(sizeof(int) * data->size);
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

int **ft_length_matrix(t_data *data, t_room *room)
{
	int count;
	int on;
	int ind;
	int i;
	int *arr;
	int len;
	int end;

	on = 0;
	i = 0;
	arr = NULL;
	data->length = (int**)malloc(sizeof(int*) * data->len);
	data->length = ft_make_matrix(data->length, data->len, 0);
	ind = ft_find_index(room, data->start);
	end = ft_find_index(room, data->end);
	count = 1;
    ft_replace_count(ind, count, data->len, data, end);
	while(1)
    {
        if (!on++)
            ft_search(ind, count, data->len, data, end);
        if (arr)
        {
            free(arr);
            arr = NULL;
        }
        if (!arr)
        {
            len = data->size;
            if (len == 0)
                break ;
            arr = ft_intcpy(arr, data->num, len);
            free(data->num);
            data->num = NULL;
            data->size = 0;
            count++;
        }
	    while (i < len)
        {
            ft_search(arr[i], count, data->len, data, end);
            i++;
        }
        i = 0;
    }
    for (int j = 0; j < data->len; ++j) {
        for (int k = 0; k < data->len; ++k) {
            ft_printf("%d ", data->length[j][k]);
        }
        ft_printf("\n");
    }
}
