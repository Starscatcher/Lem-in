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
	data->num = NULL;
	data->length = NULL;
	data->indend = 0;
	data->indstart = 0;
	data->size = 0;
	return (data);
}

t_road	*ft_create_road(t_road *road)
{
	road = (t_road*)malloc(sizeof(t_road));
	road->next = NULL;
	road->name = NULL;
	road->prev = NULL;
	return (road);
}

t_ways	*ft_create_ways(t_ways *ways)
{
	ways = (t_ways*)malloc(sizeof(t_ways));
	ways->len = 0;
	ways->ants = 0;
	ways->road = ft_create_road(ways->road);
	ways->next = NULL;
	return (ways);
}