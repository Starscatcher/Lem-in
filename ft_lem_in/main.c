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
	t_data	*data;
	char	*line;

	line = NULL;
	data = ft_create_data(data);
	data->room = ft_read(line, data);
	data->ways = ft_create_ways(NULL);
	ft_search_distance(data, data->room);
	ft_find_ways(data, data->room, data->ways);
	ft_del_last_lst(data->ways);
	ft_sort_ways(data->ways);
	ft_set_ants(data, data->ways);
	ft_move_ants(data->ways, data);
	ft_del_data(&data);
	system("leaks Lem_in");
}
