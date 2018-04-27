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
	char	*line;

	room = NULL;
	line = NULL;
	data = ft_create_data(data);
	room = ft_read(line, room, data);
	ft_way(data, room);
}
