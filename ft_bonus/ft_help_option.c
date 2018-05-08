/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:47:31 by aryabenk          #+#    #+#             */
/*   Updated: 2018/04/18 13:39:51 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void	ft_op_help(t_option *option, t_push *push)
{
	free(option);
	ft_stek_del(push);
	ft_printf(" _________________{sea wave}<HELP>{eoc}_________________\n");
	ft_printf("|                                        |\n");
	ft_printf("|        ./checker [KEYS] [STACK]        |\n");
	ft_printf("|                                        |\n");
	ft_printf("|               {sea wave}---KEYS---{eoc}               |\n");
	ft_printf("|                                        |\n");
	ft_printf("|  {sea wave}[ -l ]{eoc}   length of stack              |\n");
	ft_printf("|  {sea wave}[ -n ]{eoc}   number of commands           |\n");
	ft_printf("|  {sea wave}[ -v ]{eoc}   visualization                |\n");
	ft_printf("|  {sea wave}[ -c ]{eoc}   colour visualization         |\n");
	ft_printf("|  {sea wave}[ -k ]{eoc}   visualization with commands  |\n");
	ft_printf("|                                        |\n");
	ft_printf("|           {blue}push{eoc}                         |\n");
	ft_printf("|           {violet}swap{eoc}                         |\n");
	ft_printf("|           {green}rotate{eoc}                       |\n");
	ft_printf("|           {yellow}reverse rotate{eoc}               |\n");
	ft_printf("|________________________________________|\n");
	exit(0);
}
