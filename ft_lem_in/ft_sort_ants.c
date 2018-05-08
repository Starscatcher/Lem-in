/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 14:32:44 by aryabenk          #+#    #+#             */
/*   Updated: 2018/05/08 14:32:44 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_num(char *str)
{
	int num;

	num = (int)ft_atoi(str + 1);
	return (num);
}

static int		ft_str_sort(char **str)
{
	int i;

	i = 0;
	while (str && str[i] && str[i + 1])
	{
		if (ft_num(str[i]) > ft_num(str[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

static void		ft_print(char **ways)
{
	int i;

	i = 0;
	while (ways && ways[i])
	{
		ft_printf("%s", ways[i]);
		ways[i + 1] ? ft_printf(" ") : 0;
		i++;
	}
	ft_printf("\n");
}

void			ft_sort_ants(char *str)
{
	char	**ways;
	char	*tmp;
	int		i;

	i = 0;
	ways = ft_strsplit(str, ' ');
	ft_strdel(&str);
	while (!ft_str_sort(ways))
	{
		while (ways[i])
		{
			if (ways[i] && ways[i + 1] && ft_num(ways[i]) > ft_num(ways[i + 1]))
			{
				tmp = ways[i];
				ways[i] = ways[i + 1];
				ways[i + 1] = tmp;
			}
			i++;
		}
		i = 0;
	}
	ft_print(ways);
	ft_del_doublestr(&ways);
}
