
#include "lem_in.h"

void	ft_del_road(t_road *road)
{
	t_road	*copy;

	while(road)
	{
		copy = road->next;
		ft_strdel(&road->name);
		free(road);
		road = copy;
	}
}

void	ft_del_ways(t_ways *ways)
{
	t_ways *copy;

	while(ways)
	{
		copy = ways->next;
		ft_del_road(ways->road);
		free(ways);
		ways = copy;
	}
}

void	ft_del_room(t_room *room)
{
	t_room	*copy;

	while(room)
	{
		copy = room->next;
		ft_strdel(&room->name);
		free(room);
		room = copy;
	}
}

void	ft_del_data(t_data **data)
{
	t_data *tmp;

	tmp = *data;
	ft_del_doubleint(tmp->matrix, tmp->len);
	ft_del_doubleint(tmp->length, tmp->len);
	ft_strdel(&tmp->start);
	ft_strdel(&tmp->end);
	ft_intdel(&tmp->num);
	ft_del_room(tmp->room);
	ft_del_ways(tmp->ways);
	ft_strdel(&tmp->map);
	free(*data);
	*data = NULL;
}