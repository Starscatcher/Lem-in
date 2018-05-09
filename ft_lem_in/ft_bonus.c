/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 10:36:00 by aryabenk          #+#    #+#             */
/*   Updated: 2018/05/09 10:36:01 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_check_bonuse(t_data *data)
{
	if (data->flag->w)
		ft_ways_flag(data->ways);
	if (data->flag->l)
		ft_len_flag(data->ways);
	if (data->flag->s)
		ft_printf("Number of step is {sea wave}%d{eoc}.\n\n", data->step - 1);
}

void	ft_ways_flag(t_ways *ways)
{
	int		on;
	int		count;
	t_road	*head;

	on = 0;
	count = 1;
	while (ways)
	{
		head = ways->road;
		while (ways->road)
		{
			!on ? ft_printf("{sea wave}WAY %d:{eoc} ", count) : 0;
			ft_printf("%s", ways->road->name);
			ways->road->next ? ft_printf(" -> ") : 0;
			ways->road = ways->road->next;
			on++;
		}
		ways->road = head;
		on = 0;
		count++;
		ft_printf("\n");
		ways = ways->next;
	}
	ft_printf("\n");
}

void	ft_len_flag(t_ways *ways)
{
	int len;
	int on;
	int count;

	len = 0;
	on = 0;
	count = 1;
	while (ways)
	{
		while (ways->road)
		{
			!on ? ft_printf("Length of the %d way is ", count) : 0;
			len++;
			ways->road = ways->road->next;
			on++;
		}
		ft_printf("{sea wave}%d{eoc}.", len);
		len = 0;
		on = 0;
		count++;
		ft_printf("\n");
		ways = ways->next;
	}
	ft_printf("\n");
}

void	ft_ants_flag(t_data *data)
{
	char *num;

	data->on++;
	num = ft_itoa(data->ants);
	data->map = ft_reallcat(data->map, num);
	data->map = ft_reallcat(data->map, "\n");
	ft_strdel(&num);
}

void	ft_help_flag(t_data *data)
{
	ft_del_data(&data);
	ft_printf(" _________________{sea wave}<HELP>{eoc}_________________\n");
	ft_printf("|                                        |\n");
	ft_printf("|        ./lem-in [KEYS] < [map]         |\n");
	ft_printf("|                                        |\n");
	ft_printf("|               {sea wave}---KEYS---{eoc}               |\n");
	ft_printf("|                                        |\n");
	ft_printf("|  {sea wave}[ -h ]{eoc}           help                 |\n");
	ft_printf("|  {sea wave}[ -w ]{eoc}           all ways             |\n");
	ft_printf("|  {sea wave}[ -l ]{eoc}           length of each way   |\n");
	ft_printf("|  {sea wave}[ -s ]{eoc}           number of step       |\n");
	ft_printf("|  {sea wave}[ -f ] file name{eoc} read from file       |\n");
	ft_printf("|  {sea wave}[ -a ] value{eoc}     number of ants       |\n");
	ft_printf("|  {sea wave}[ -c ]{eoc}           colour               |\n");
	ft_printf("|                   {red}<START>{eoc}              |\n");
	ft_printf("|                   {green}<END>{eoc}                |\n");
	ft_printf("|________________________________________|\n\n");
	exit(0);
}
