/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 16:35:16 by aryabenk          #+#    #+#             */
/*   Updated: 2018/05/08 16:35:16 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_find(char *arr, char elem)
{
	int j;

	j = 0;
	while (arr && arr[j])
	{
		if (arr[j] == elem)
			return (1);
		j++;
	}
	return (0);
}

int			ft_is_flag(char f, char s)
{
	if (f != '-')
		return (0);
	if (ft_find("wchslro", s))
		return (1);
	else
		return (0);
}

void	ft_read_flags(int argc, char **argv, t_flag *flag)
{
	int i;

	i = 1;
	while (i < argc && ft_is_flag(argv[i][0], argv[i][1]) && !argv[i][2])
	{
		flag->w += argv[i][1] == 'w' ? 1 : 0;
		flag->c += argv[i][1] == 'c' ? 1 : 0;
		flag->h += argv[i][1] == 'h' ? 1 : 0;
		flag->s += argv[i][1] == 's' ? 1 : 0;
		flag->l += argv[i][1] == 'l' ? 1 : 0;
		flag->r += argv[i][1] == 'r' ? 1 : 0;
		flag->o += argv[i][1] == 'o' ? 1 : 0;
		i++;
	}
	if (i < argc)
		flag->h++;
}
