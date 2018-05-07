/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:34:02 by aryabenk          #+#    #+#             */
/*   Updated: 2018/04/19 15:34:03 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include "../libftprintf/libft/libft.h"

typedef struct			s_road
{
  int				ant;
  char				*name;
  struct s_road		*next;
  struct s_road		*prev;
}						t_road;

typedef struct			s_ways
{
  int				ants;
  int				len;
  struct s_road		*road;
  struct s_ways		*next;
}						t_ways;

typedef struct			s_room
{
  char				*name;
  int				start;
  int				end;
  int				x;
  int				y;
  struct s_room		*next;
}						t_room;

typedef struct			s_data
{
	int	ants;
	char *map;
	int	**matrix;
	int **length;
  	int len;
	char *start;
	char *end;
	int size;
	int *num;
	int indend;
  	int indstart;
  	t_room	*room;
  	t_ways	*ways;
}						t_data;

int						ft_print_error(int i, char *str);
void					ft_del_data(t_data **data);
void					ft_move_ants(t_ways *ways, t_data *data);
void					ft_sort_ways(t_ways *ways);
void					ft_del_last_lst(t_ways *ways);
void					ft_set_ants(t_data *data, t_ways *ways);
t_road					*ft_create_road(t_road *road);
char					*ft_find_name(t_room *room, int ind);
int 					ft_find_index(t_room *room, char *name);
void					ft_find_ways(t_data *data, t_room *room, t_ways *ways);
t_ways					*ft_create_ways(t_ways *ways);
void					ft_search_distance(t_data *data, t_room *room);
t_data					*ft_create_data(t_data *data);
int						ft_find_ind(char *name, t_room *room);
int						ft_check_arr_len(char **arr);
int						**ft_make_matrix(int **matrix, int len, int num);
int						ft_check_room_len(t_room *room);
t_room					*ft_add_rooms(char *li, int *se, t_data *d, t_room *r);
int						ft_check_strdigit(char *arr);
t_room					*ft_create_room(t_room *room);
int						ft_room_error(char *line, t_data *data);
char					**ft_link_error(char **line, int fd, t_data *data);
t_room					*ft_read(char *line, t_data *data);
int 					ft_check_room(t_room *ro, char *name, int x, int y);

#endif
