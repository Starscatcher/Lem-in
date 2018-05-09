/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:19:30 by aryabenk          #+#    #+#             */
/*   Updated: 2018/05/09 15:19:31 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_write_ants(t_data *data, ssize_t *ants, char **line)
{
	char	*num;

	if (data->ants)
	{
		num = ft_itoa(data->ants);
		data->map = ft_reallcat(data->map, num);
		data->map = ft_reallcat(data->map, "\n");
		*ants = data->ants;
		ft_strdel(&num);
	}
	else
	{
		data->map = ft_reallcat(data->map, *line);
		data->map = ft_reallcat(data->map, "\n");
		*ants = ft_atoi(*line);
	}
	ft_strdel(line);
	data->on++;
}

static void		ft_ants_not_integer(int ants, char **line, t_data *data)
{
	if (ants < 1 || ants > 2147483647)
	{
		if (*line)
			ft_strdel(line);
		ft_print_error(5, "Number of ants should be a positive integer", data);
	}
}

static void		ft_help_find(char **line, t_data *data)
{
	if (!*line)
		ft_print_error(1, "Map is empty", data);
	if (!ft_check_strdigit(*line) && *line && (*line)[0] == '#' \
				&& ft_strcmp(*line, "##start") && ft_strcmp(*line, "##end"))
	{
		data->map = ft_reallcat(data->map, *line);
		data->map = ft_reallcat(data->map, "\n");
	}
}

ssize_t			ft_find_ants(char **line, int fd, t_data *data)
{
	ssize_t ants;

	ants = 0;
	while (!ants && get_next_line(fd, line))
	{
		ft_help_find(line, data);
		if ((*line)[0] == '#' && ft_strcmp(*line, "##start") \
				&& ft_strcmp(*line, "##end"))
			ft_strdel(line);
		else if (ft_check_strdigit(*line))
			ft_write_ants(data, &ants, line);
		else if (!ft_check_strdigit(*line))
		{
			if (data->ants)
				break ;
			ft_strdel(line);
			ft_print_error(5, "Number of ants isn't a positive integer", data);
		}
	}
	!data->ants ? ft_strdel(line) : 0;
	ants = data->ants ? data->ants : ants;
	ft_ants_not_integer(ants, line, data);
	return (ants);
}
