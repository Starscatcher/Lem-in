/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:03:50 by aryabenk          #+#    #+#             */
/*   Updated: 2018/05/09 13:03:51 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_print_colour(char **ways, int i, t_data *data)
{
	int j;

	j = 0;
	while (ways[i][j] && ways[i][j] != '-')
		j++;
	j++;
	if (!ft_strcmp(ways[i] + j, data->end))
	{
		if (ft_atoi(ways[i] + 1) == data->a)
			data->a++;
		ft_printf("{green}%s{eoc}", ways[i]);
	}
	else if (ft_atoi(ways[i] + 1) == data->a)
	{
		data->a++;
		ft_printf("{red}%s{eoc}", ways[i]);
	}
	else
		ft_printf("%s", ways[i]);
}

int			ft_print_ants(char **ways, t_data *data)
{
	int i;

	i = 0;
	while (ways && ways[i])
	{
		if (data->flag->c)
			ft_print_colour(ways, i, data);
		else
			ft_printf("%s", ways[i]);
		ways[i + 1] ? ft_printf(" ") : 0;
		i++;
	}
	data->step++;
	ft_printf("\n");
	return (i);
}
