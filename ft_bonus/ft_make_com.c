/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:20:17 by aryabenk          #+#    #+#             */
/*   Updated: 2018/03/31 13:20:18 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

static void	ft_commands_error(t_push *push)
{
	ft_stek_del(push);
	ft_putstr("Error\n");
	exit(1);
}

void		ft_make_commands(char *str, t_push *push, int error)
{
	error = ft_strequ(str, "sa") ? ft_s(push, 'a', 0) : 0;
	error += ft_strequ(str, "sb") ? ft_s(push, 'b', 0) : 0;
	error += ft_strequ(str, "pa") ? ft_p(push, 'a') : 0;
	error += ft_strequ(str, "pb") ? ft_p(push, 'b') : 0;
	error += ft_strequ(str, "ra") ? ft_r(push, 'a', 0) : 0;
	error += ft_strequ(str, "rb") ? ft_r(push, 'b', 0) : 0;
	error += ft_strequ(str, "rra") ? ft_rr(push, 'a', 0) : 0;
	error += ft_strequ(str, "rrb") ? ft_rr(push, 'b', 0) : 0;
	if (ft_strequ(str, "rr"))
	{
		error += ft_r(push, 'a', 0);
		error += ft_r(push, 'b', 0);
	}
	else if (ft_strequ(str, "rrr"))
	{
		error += ft_rr(push, 'a', 0);
		error += ft_rr(push, 'b', 0);
	}
	else if (ft_strequ(str, "ss"))
	{
		error += ft_s(push, 'a', 0);
		error += ft_s(push, 'b', 0);
	}
	error == 0 ? ft_commands_error(push) : 0;
}
