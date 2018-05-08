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

int		ft_print_error(int i, char *str)
{
	errno = i;
	perror(str);
	exit(1);
}

void	ft_start_end_error(char *line, int *se)
{
	if (line && (!ft_strcmp(line, "##start")))
		*se = *se == 0 ? 1 : ft_print_error(1, "Doesn't valid start/end");
	else if (line && !ft_strcmp(line, "##end"))
		*se = *se == 0 ? 2 : ft_print_error(1, "Doesn't valid start/end");
}

char	**ft_link_error(char **line, int fd, t_data *data)
{
	char **links;

	while (*line && (*line)[0] && (*line)[0] == '#')
	{
		if (*line && (!ft_strcmp(*line, "##start") || \
			!ft_strcmp(*line, "##end")))
		{
			ft_strdel(line);
			ft_del_data(&data);
			ft_print_error(1, "More than one start/end");
		}
		ft_strdel(line);
		get_next_line(fd, line);
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

int		ft_room_error(char *line)
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
	ft_del_doublestr(&rooms);
	return (2);
}
