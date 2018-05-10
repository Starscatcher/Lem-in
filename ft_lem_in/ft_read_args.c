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

char			*ft_find_room(char *line, int fd, t_data *data, t_room *copy)
{
	int		se;

	se = 0;
	while ((data->on++ && data->flag->a && ft_room_error(line, data) != 2) \
		|| (get_next_line(fd, &line) && ft_room_error(line, data) != 2))
	{
		data->map = ft_reallcat(data->map, line);
		data->map = ft_reallcat(data->map, "\n");
		ft_start_end_error(line, &se, data);
		if (ft_room_error(line, data) == 1)
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

void			ft_find_links(char *line, int fd, t_room *room, t_data *data)
{
	char	**links;

	data->matrix = ft_make_matrix(NULL, data->len, 0);
	links = ft_link_error(&line, fd, data);
	data->map = ft_reallcat(data->map, line);
	data->map = ft_reallcat(data->map, "\n");
	data->matrix[ft_find_ind(links[0], room, data)]\
	[ft_find_ind(links[1], room, data)] = 1;
	data->matrix[ft_find_ind(links[1], room, data)]\
	[ft_find_ind(links[0], room, data)] = 1;
	ft_strdel(&line);
	ft_del_doublestr(&links);
	while (get_next_line(fd, &line))
	{
		links = ft_link_error(&line, fd, data);
		data->map = ft_reallcat(data->map, line);
		data->map = ft_reallcat(data->map, "\n");
		data->matrix[ft_find_ind(links[0], room, data)]\
		[ft_find_ind(links[1], room, data)] = 1;
		data->matrix[ft_find_ind(links[1], room, data)]\
		[ft_find_ind(links[0], room, data)] = 1;
		ft_strdel(&line);
		ft_del_doublestr(&links);
	}
}

t_room			*ft_read(char *line, t_data *data)
{
	int		fd;

	fd = data->flag->f ? open(data->flag->input, O_RDONLY) : 0;
	if (data->flag->a)
		data->ants = (int)data->flag->ants;
	data->ants = (int)ft_find_ants(&line, fd, data);
	if (!data->ants)
		ft_print_error(1, "Ants are absent", data);
	if (!data->on && data->flag->a)
		ft_ants_flag(data);
	line = ft_find_room(line, fd, data, NULL);
	if (!data->start || !data->end)
	{
		ft_strdel(&line);
		ft_print_error(1, "There is no start/end", data);
	}
	data->len = ft_check_room_len(data->room);
	ft_find_links(line, fd, data->room, data);
	return (data->room);
}
