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

int	main(int argc, char **argv)
{
	t_data	*data;
	char	*line;

	line = NULL;
	data = NULL;
	data = ft_create_data(data);
	data->flag = ft_create_flag(data->flag);
	ft_read_flags(argc, argv, data->flag, data);
	data->flag->h ? ft_help_flag(data) : 0;
	data->room = ft_read(line, data);
	data->ways = ft_create_ways(NULL);
	ft_search_distance(data, data->room);
	ft_find_ways(data, data->room, data->ways);
	if (!data->ways->len)
		ft_print_error(5, "There is no any way", data);
	ft_del_last_lst(data->ways);
	ft_sort_ways(data->ways);
	ft_set_ants(data, data->ways);
	ft_printf("%s\n", data->map);
	ft_move_ants(data->ways, data);
	ft_check_bonuse(data);
	ft_del_data(&data);
	system("leaks lem-in");
}
