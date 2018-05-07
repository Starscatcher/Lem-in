/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:33:04 by aryabenk          #+#    #+#             */
/*   Updated: 2018/04/19 15:33:04 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_print_error(int i, char *str)
{
	errno = i;
	perror(str);
	system("leaks Lem_in");
	exit(1);
}

int 	ft_check_room(t_room *room, char *name, int x, int y)
{
	while (room)
	{
		if (ft_strequ(room->name, name))
			return (0);
		if (room->x == x && room->y == y)
			return (1);
		room = room->next;
	}
	return (2);
}

char	**ft_link_error(char **line, int fd, t_data *data)
{
	char **links;

	while (*line && (*line)[0] && (*line)[0] == '#')
	{
		if (*line && (!ft_strcmp(*line, "##start") || !ft_strcmp(*line, "##end")))
		{
			ft_strdel(line);
			ft_del_data(&data);
			ft_print_error(1, "More than one start/end");
		}
		else
		{
			ft_strdel(line);
			get_next_line(fd, line);
		}
	}
	links = ft_strsplit(*line, '-');
	if (ft_check_arr_len(links) != 2)
	{
		ft_strdel(line);
		ft_del_doublestr(&links);
		ft_del_data(&data);
		ft_print_error(1, "Not valid link");
	}
	return (links);
}


int		ft_room_error(char *line, t_data *data)
{
	int		i;
	char	**rooms;

	if (line && line[0] && line[0] == '#')
		return (0);
	i = 1;
	rooms = ft_strsplit(line, ' ');
	if (ft_check_arr_len(rooms) == 3)
	{
		while (rooms && rooms[i])
		{
			if (!ft_check_strdigit(rooms[i]))
			{
				ft_strdel(&line);
				ft_del_doublestr(&rooms);
				ft_print_error(1, "Not valid coordinates");
			}
			i++;
		}
		ft_del_doublestr(&rooms);
		return (1);
	}
	else if (ft_check_arr_len(rooms) != 3)
	{
		ft_del_doublestr(&rooms);
		return (2);
	}
}
