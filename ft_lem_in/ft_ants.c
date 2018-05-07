
#include <zconf.h>
#include "lem_in.h"

void	ft_set_ants(t_data *data, t_ways *ways)
{
	t_ways	*head;
	int ants;

	head = ways;
	ants = data->ants;
	while(ants > 0)
	{
		if (ways && ways->next && ways->len + ways->ants <= ways->next->len + ways->next->ants)
		{
			ways->ants++;
			ants--;
			ways = head;
		}
		else if (!ways->next)
		{
			ways->ants++;
			ants--;
			ways = head;
		}
		else
			ways = ways->next;
	}
}

void 	ft_print_ants(t_ways *ways)
{
	t_road	*head;

	while (ways)
	{
		head = ways->road;
		while (ways->road)
		{
			if (ways->road->ant)
				ft_printf("L%d-%s ", ways->road->ant, ways->road->name);
			ways->road = ways->road->next;
		}
		ways->road = head;
		ways = ways->next;
	}
	ft_printf("\n");
}

int 	ft_is_ant(t_ways *ways)
{
	t_road *head;

	head = ways->road;
	while (head && !head->ant)
		head = head->next;
	if (!head)
		return(0);
	else
		return(1);
}

void	ft_move_ants(t_ways *ways, t_data *data)
{
	t_ways	*head;
	int ant;
	int tmp;

	ant = 1;
	tmp = 0;
	head = ways;
	while(tmp != data->ants)
	{
		while(ways && tmp != data->ants)
		{
			if (ways && ft_is_ant(ways))
			{
				while(ways->road && !ways->road->ant)
					ways->road = ways->road->next;
			}
			if (ways && ways->road && ways->road->ant)
			{
				while (ways->road && ways->road->ant && ways->road->next)
					ways->road = ways->road->next;
				if (ways->road->ant)
				{
					ways->road->ant = 0;
					tmp++;
				}
				while (ways->road && ways->road->prev)
				{
					ways->road->ant = ways->road->prev->ant;
					ways->road = ways->road->prev;
					ways->road->ant = 0;
				}
			}
			if (ways->ants > 0)
			{
				ways->road->ant = ant;
				ways->ants--;
				ways = ways->next;
				ant++;
			}
			else
				ways = ways->next;
		}
		ways = head;
		ft_print_ants(ways);
	}
}
