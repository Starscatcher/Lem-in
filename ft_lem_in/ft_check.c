/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 13:12:10 by aryabenk          #+#    #+#             */
/*   Updated: 2018/04/27 13:12:10 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*ft_find_name(t_room *room, int ind)
{
	int i;

	i = 0;
	while (i != ind)
	{
		room = room->next;
		i++;
	}
	return (room->name);
}

int ft_find_index(t_room *room, char *name)
{
	int ind;

	ind = 0;
	while (room && ft_strcmp(room->name, name))
	{
		room = room->next;
		ind++;
	}
	return (ind);
}

int	ft_check_strdigit(char *arr)
{
	int i;

	i = 0;
	while (arr && arr[i])
	{
		if (!ft_isdigit(arr[i]))
			return (0);
		i++;
	}
	return (i);
}

int	ft_check_arr_len(char **arr)
{
	int i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

int	ft_check_room_len(t_room *room)
{
	int len;

	len = 0;
	if (room == NULL)
		return (0);
	while (room)
	{
		room = room->next;
		len++;
	}
	return (len);
}
