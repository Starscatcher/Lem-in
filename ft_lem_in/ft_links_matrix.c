/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_links_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 13:12:34 by aryabenk          #+#    #+#             */
/*   Updated: 2018/04/27 13:12:35 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_find_ind(char *name, t_room *room)
{
	int i;

	i = 0;
	while (room && ft_strcmp(name, room->name))
	{
		room = room->next;
		i++;
	}
	if (!room)
		ft_print_error(1, "Not valid link");
	return (i);
}

int	**ft_make_matrix(int **matrix, int len, int num)
{
	int i;
	int j;

	i = 0;
	j = 0;
	matrix = (int**)malloc(sizeof(int*) * len);
	while (i != len)
	{
		matrix[i] = (int*)malloc(sizeof(int) * len);
		while (j != len)
		{
			matrix[i][j] = num;
			j++;
		}
		j = 0;
		i++;
	}
	return (matrix);
}
