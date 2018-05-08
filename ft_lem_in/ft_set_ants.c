/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:34:56 by aryabenk          #+#    #+#             */
/*   Updated: 2018/05/08 15:34:56 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_set_ants(t_data *data, t_ways *ways)
{
	t_ways	*head;
	int		ants;
	int		k;

	head = ways;
	ants = data->ants;
	while (ants > 0)
	{
		k = ways && ways->next && ways->len == ways->next->len ? 0 : 1;
		if (ways && ways->next && ways->len + ways->ants + k <= \
			ways->next->len + ways->next->ants)
		{
			ways->ants++;
			ants--;
			ways = head;
		}
		else if (ways && !ways->next)
		{
			ways->ants++;
			ants--;
			ways = head;
		}
		else
			ways && ways->next ? ways = ways->next : 0;
	}
}

char	*ft_make_str(char *str, t_ways *ways)
{
	char	*tmp;

	str = ft_reallcat(str, "L");
	tmp = ft_itoa(ways->road->ant);
	str = ft_reallcat(str, tmp);
	ft_strdel(&tmp);
	str = ft_reallcat(str, "-");
	str = ft_reallcat(str, ways->road->name);
	str = ft_reallcat(str, " ");
	return (str);
}
