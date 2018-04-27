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

int		ft_way(t_data *data, t_room *room)
{
	t_start	*start;
	t_end	*end;
	int i;
	int j;

	i = 0;
	j = 0;
	start = ft_create_start(start);
	end = ft_create_end(end);
	while (ft_strcmp(start[i], end[j]))
	{
		if ()
	}
}
