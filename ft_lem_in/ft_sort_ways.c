/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_ways.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 14:57:06 by aryabenk          #+#    #+#             */
/*   Updated: 2018/05/08 14:57:06 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_ways_sort(t_ways *ways)
{
	while (ways && ways->next)
	{
		if (ways->len > ways->next->len)
			return (0);
		ways = ways->next;
	}
	return (1);
}

void	ft_sort_ways(t_ways *ways)
{
	t_ways	*head;
	int		a;
	int		l;
	t_road	*r;

	head = ways;
	while (!ft_ways_sort(head))
	{
		if (!ways->next)
			ways = head;
		if (ways->len > ways->next->len)
		{
			a = ways->ants;
			l = ways->len;
			r = ways->road;
			ways->ants = ways->next->ants;
			ways->len = ways->next->len;
			ways->road = ways->next->road;
			ways->next->ants = a;
			ways->next->len = l;
			ways->next->road = r;
		}
		if (ways->next)
			ways = ways->next;
	}
}
