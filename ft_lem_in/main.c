/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:57:37 by aryabenk          #+#    #+#             */
/*   Updated: 2018/04/19 15:57:38 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_room	*room;
	t_data	*data;
	t_ways	*ways;
	char	*line;

	room = NULL;
	line = NULL;
	data = ft_create_data(data);
	room = ft_read(line, room, data);
	ways = ft_create_ways(ways);
	ft_search_distance(data, room);
	ft_find_ways(data, room, ways);
/*	for (int j = 0; j < data->len; ++j) {
		for (int k = 0; k < data->len; ++k) {
			ft_printf("%d ", data->length[j][k]);
		}
		ft_printf("\n");
	}*/
}
