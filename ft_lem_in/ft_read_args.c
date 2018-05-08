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

static t_room	*ft_make_data(t_room *room, t_room **copy)
{
	room = ft_create_room(room);
	*copy = room;
	return (room);
}

char			*ft_find_room(char *line, int fd, t_data *data)
{
	t_room	*copy;
	int		se;

	copy = NULL;
	se = 0;
	while (get_next_line(fd, &line) && ft_room_error(line) != 2)
	{
		data->map = ft_reallcat(data->map, line);
		data->map = ft_reallcat(data->map, "\n");
		ft_start_end_error(line, &se);
		if (ft_room_error(line) == 1)
		{
			if (!data->room)
				data->room = ft_make_data(data->room, &copy);
			else
			{
				data->room->next = ft_create_room(data->room);
				data->room = data->room->next;
			}
			ft_add_rooms(line, &se, data, copy);
		}
		ft_strdel(&line);
	}
	data->room = copy;
	return (line);
}

int				**ft_find_links(char *line, int fd, t_room *room, t_data *data)
{
	int		**matrix;
	char	**links;

	matrix = ft_make_matrix(NULL, data->len, 0);
	links = ft_link_error(&line, fd, data);
	data->map = ft_reallcat(data->map, line);
	data->map = ft_reallcat(data->map, "\n");
	matrix[ft_find_ind(links[0], room)][ft_find_ind(links[1], room)] = 1;
	matrix[ft_find_ind(links[1], room)][ft_find_ind(links[0], room)] = 1;
	ft_strdel(&line);
	ft_del_doublestr(&links);
	while (get_next_line(fd, &line))
	{
		links = ft_link_error(&line, fd, data);
		data->map = ft_reallcat(data->map, line);
		data->map = ft_reallcat(data->map, "\n");
		matrix[ft_find_ind(links[0], room)][ft_find_ind(links[1], room)] = 1;
		matrix[ft_find_ind(links[1], room)][ft_find_ind(links[0], room)] = 1;
		ft_strdel(&line);
		ft_del_doublestr(&links);
	}
	return (matrix);
}

int				ft_find_ants(char **line, int fd, t_data *data)
{
	int ants;

	ants = 0;
	while (!ants && get_next_line(fd, line))
	{
		if (!*line)
			ft_print_error(1, "Map is empty");
		data->map = ft_reallcat(data->map, *line);
		data->map = ft_reallcat(data->map, "\n");
		if ((*line)[0] == '#' && (*line)[1] != '#')
			ft_strdel(line);
		else if (ft_check_strdigit(*line))
			ants = (int)ft_atoi(*line);
		else if (!ft_check_strdigit(*line))
		{
			ft_strdel(line);
			ft_print_error(1, "Number of ants should be integer");
		}
	}
	ft_strdel(line);
	return (ants);
}

t_room			*ft_read(char *line, t_data *data)
{
	int fd;

	fd = 0;
	if (!(data->ants = ft_find_ants(&line, fd, data)))
		ft_print_error(1, "Ants are absent");
	line = ft_find_room(line, fd, data);
	if (!data->start || !data->end)
	{
		ft_strdel(&line);
		ft_del_data(&data);
		ft_print_error(1, "There is no start/end");
	}
	data->len = ft_check_room_len(data->room);
	data->matrix = ft_find_links(line, fd, data->room, data);
	return (data->room);
}
