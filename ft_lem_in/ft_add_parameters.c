/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_parameters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 13:12:56 by aryabenk          #+#    #+#             */
/*   Updated: 2018/04/27 13:12:56 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*ft_add_rooms(char *line, int *se, t_data *data, t_room *room)
{
	char	**args;
	int i;

	args = ft_strsplit(line, ' ');
	i = ft_check_room(room, args[0], ft_atoi(args[1]), ft_atoi(args[2]));
	if (i < 2)
	{
		ft_strdel(&line);
		ft_del_data(&data);
		i == 0 ? ft_print_error(1, "Room name already exist") : \
				ft_print_error(1, "Room coordinate already exist");
	}
	data->room->name = ft_strdup(args[0]);
	data->room->x = (int)ft_atoi(args[1]);
	data->room->y = (int)ft_atoi(args[2]);
	if (*se == 1)
	{
		data->room->start++;
		data->start = ft_strdup(data->room->name);
	}
	else if (*se == 2)
	{
		data->room->end++;
		data->end = ft_strdup(data->room->name);
	}
	*se = 0;
	ft_del_doublestr(&args);
}
