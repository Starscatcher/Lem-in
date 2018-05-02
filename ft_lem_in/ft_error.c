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

void	ft_print_error(int i, char *str)
{
	errno = i;
	perror(str);
	exit(1);
}

char	**ft_link_error(char *line, int fd)
{
	char **links;

	while (line && line[0] && line[0] == '#')
	{
		if (line && (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end")))
			ft_print_error(1, "More than one start/end");
		else
			get_next_line(fd, &line);
	}
	links = ft_strsplit(line, '-');
	if (ft_check_arr_len(links) != 2)
		ft_print_error(1, "Not valid link");
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
				ft_print_error(1, "Not valid coordinates");
			i++;
		}
		return (1);
	}
	else if (ft_check_arr_len(rooms) == 1)
		return (2);
	else
		ft_print_error(1, "Not valid link");
}
