/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ants.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 14:32:11 by aryabenk          #+#    #+#             */
/*   Updated: 2018/05/08 14:32:12 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_is_ant(t_ways *ways)
{
	t_road *head;

	head = ways->road;
	while (head && !head->ant)
		head = head->next;
	if (!head)
		return (0);
	else
		return (1);
}

void			ft_save_ants(t_ways *ways, t_data *data)
{
	t_road	*head;
	char	*str;

	str = NULL;
	while (ways)
	{
		head = ways->road;
		while (ways->road)
		{
			if (ways->road->ant)
				str = ft_make_str(str, ways);
			ways->road = ways->road->next;
		}
		ways->road = head;
		ways = ways->next;
	}
	ft_sort_ants(str, data);
}

static void		ft_move_ant(t_ways *ways, int *tmp)
{
	while (ways->road && ways->road->ant && ways->road->next)
		ways->road = ways->road->next;
	if (ways->road->ant)
	{
		ways->road->ant = 0;
		++*tmp;
	}
	while (ways->road && ways->road->prev)
	{
		ways->road->ant = ways->road->prev->ant;
		ways->road = ways->road->prev;
		ways->road->ant = 0;
	}
}

static t_ways	*ft_help_move(t_ways *ways, int *ant)
{
	ways->road->ant = *ant;
	ways->ants--;
	ways = ways->next;
	++*ant;
	return (ways);
}

void			ft_move_ants(t_ways *ways, t_data *data)
{
	t_ways	*head;
	int		ant;
	int		tmp;

	ant = 1;
	tmp = 0;
	head = ways;
	while (tmp != data->ants)
	{
		while (ways && tmp != data->ants)
		{
			if (ft_is_ant(ways))
				while (ways->road && !ways->road->ant)
					ways->road = ways->road->next;
			if (ways->road && ways->road->ant)
				ft_move_ant(ways, &tmp);
			if (ways->ants > 0)
				ways = ft_help_move(ways, &ant);
			else
				ways = ways->next;
		}
		ways = head;
		ft_save_ants(ways, data);
	}
}
