/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:05:29 by aryabenk          #+#    #+#             */
/*   Updated: 2018/04/11 14:05:30 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

t_option	*ft_create_option(t_option *option)
{
	option = (t_option*)malloc(sizeof(t_option));
	option->c = 0;
	option->n = 0;
	option->v = 0;
	option->h = 0;
	option->l = 0;
	option->k = 0;
	return (option);
}


