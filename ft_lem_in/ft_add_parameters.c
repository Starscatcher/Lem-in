/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_parameters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 13:12:56 by aryabenk          #+#    #+#             */
/*   Updated: 2018/04/27 13:12:56 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*ft_add_rooms(char *line, t_room *room)
{
	char	**param;

	param = ft_strsplit(line, ' ');
	room->name = ft_strdup(param[0]);
	room->x = ft_atoi(param[1]);
	room->y = ft_atoi(param[2]);
}
