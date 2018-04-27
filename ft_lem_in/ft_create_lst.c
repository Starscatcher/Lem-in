/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 11:45:13 by aryabenk          #+#    #+#             */
/*   Updated: 2018/04/23 11:45:14 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*ft_create_room(t_room *room)
{
	room = (t_room*)malloc(sizeof(t_room));
	room->name = NULL;
	room->start = 0;
	room->end = 0;
	room->x = 0;
	room->y = 0;
	room->next = 0;
	return (room);
}

t_data	*ft_create_data(t_data *data)
{
	data = (t_data*)malloc(sizeof(t_data));
	data->matrix = NULL;
	data->ants = 0;
	data->len = 0;
	data->start = NULL;
	data->end = NULL;
	return (data);
}

t_start	*ft_create_start(t_start *start)
{
	start = (t_start*)malloc(sizeof(t_start));
	start->first = (char**)malloc(sizeof(char*) * 2);
	start->first[1] == '\0';
	return (start);
}

t_end	*ft_create_end(t_end *end)
{
	end = (t_end*)malloc(sizeof(t_end));
	end->second = (char**)malloc(sizeof(char*) * 2);
	end->second[1] == '\0';
	return (end);
}