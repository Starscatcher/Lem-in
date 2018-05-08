/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:44:14 by aryabenk          #+#    #+#             */
/*   Updated: 2018/05/08 15:44:15 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_check_room(t_room *room, char *name, int x, int y)
{
	while (room && room->name)
	{
		if (ft_strequ(room->name, name))
			return (0);
		if (room->x == x && room->y == y)
			return (1);
		room = room->next;
	}
	return (2);
}
