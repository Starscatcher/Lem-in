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
	if (ft_find("wchslfa", s))
		return (1);
	else
		return (0);
}

static void	ft_ants(char **argv, int *i, t_flag *flag, t_data *data)
{
	ssize_t num;

	flag->a = 1;
	num = argv[++*i] ? ft_atoi(argv[*i]) : \
		ft_print_error(1, "Write a number of ants", data);
	flag->ants = num;
	if (flag->ants < 1 || flag->ants > 2147483647)
		ft_print_error(1, "Number of ants should be a positive integer", data);
}

void		ft_read_flags(int argc, char **argv, t_flag *flag, t_data *data)
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
		if (argv[i][1] == 'f')
		{
			flag->f = 1;
			if (argv[++i])
				flag->input = argv[i];
			else
				ft_print_error(1, "Write a file name", data);
		}
		else if (argv[i][1] == 'a')
			ft_ants(argv, &i, flag, data);
		i++;
	}
	flag->h += i < argc ? 1 : 0;
}
