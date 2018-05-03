/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:33:18 by aryabenk          #+#    #+#             */
/*   Updated: 2018/04/19 15:33:20 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_start_end(int *k, char *line, t_room *room, int fd)
{
	if (*k)
		ft_print_error(1, "More than one start/end");
	if (!get_next_line(fd, &line))
		ft_print_error(1, "Not valid start/end");
	ft_room_error(line);
	room = ft_add_rooms(line, room);
	return (++*k);
}

int		**ft_find_links(char *line, int fd, t_room *room, int len)
{
	int		**matrix;
	char	**links;

	links = NULL;
	matrix = ft_make_matrix(matrix, len, 0);
	links = ft_link_error(line, fd);
	matrix[ft_find_ind(links[0], room)][ft_find_ind(links[1], room)] = 1;
	matrix[ft_find_ind(links[1], room)][ft_find_ind(links[0], room)] = 1;
	while (get_next_line(fd, &line))
	{
		links = ft_link_error(line, fd);
		matrix[ft_find_ind(links[0], room)][ft_find_ind(links[1], room)] = 1;
		matrix[ft_find_ind(links[1], room)][ft_find_ind(links[0], room)] = 1;
	}
	return (matrix);
}

t_room	*ft_find_room(char *line, int fd, t_room *room, t_data *data)
{
	int		start;
	int		end;
	t_room	*copy;

	start = 0;
	end = 0;
	while (get_next_line(fd, &line))
	{
		if (!room)
		{
			room = ft_create_room(room);
			copy = room;
		}
		if (ft_room_error(line) == 2)
		{
			data->len = ft_check_room_len(copy);
			data->matrix = ft_find_links(line, fd, copy, data->len);
			break ;
		}
		else if (ft_room_error(line))
		{
			room->next = ft_create_room(room);
			room = room->next;
		}
		if (line && !ft_strcmp(line, "##start"))
		{
			room->start = ft_start_end(&start, line, room, fd);
			data->start = ft_strdup(room->name);
		}
		else if (!ft_strcmp(line, "##end"))
		{
			if (!end)
			{
				room->next = ft_create_room(room);
				room = room->next;
			}
			room->end = !ft_start_end(&end, line, room, fd);
			data->end = ft_strdup(room->name);
		}
		else if (ft_room_error(line) == 1)
			ft_add_rooms(line, room);
	}
	return (copy);
}

int		ft_find_ants(char *line, int fd)
{
	int ants;

	ants = 0;
	get_next_line(fd, &line);
	if (!line)
		ft_print_error(1, "Map is empty");
	while (!ants)
	{
		while (line[0] == '#' && line[1] != '#')
			get_next_line(fd, &line);
		if (!ft_check_strdigit(line))
			ft_print_error(1, "Not valid count of ants");
		ants = ft_atoi(line);
	}
	return (ants);
}

t_room	*ft_read(char *line, t_room *room, t_data *data)
{
	int fd;

	fd = open("../1", O_RDONLY);
	data->ants = ft_find_ants(line, fd);
	room = ft_find_room(line, fd, room, data);
	return (room);
}
