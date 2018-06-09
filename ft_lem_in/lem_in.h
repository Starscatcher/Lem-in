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

typedef struct			s_flag
{
	int		w;
	int		c;
	int		h;
	int		s;
	int		l;
	int		f;
	int		a;
	char	*input;
	ssize_t	ants;
}						t_flag;

typedef struct			s_road
{
	int					ant;
	char				*name;
	struct s_road		*next;
	struct s_road		*prev;
}						t_road;

typedef struct			s_ways
{
	int					ants;
	int					len;
	struct s_road		*road;
	struct s_ways		*next;
}						t_ways;

typedef struct			s_room
{
	char				*name;
	int					start;
	int					end;
	int					x;
	int					y;
	struct s_room		*next;
}						t_room;

typedef struct			s_data
{
	int					ants;
	char				*map;
	int					**matrix;
	int					**length;
	int					len;
	char				*start;
	char				*end;
	int					size;
	int					*num;
	int					indend;
	int					indstart;
	int					step;
	int					a;
	int					on;
	t_room				*room;
	t_ways				*ways;
	t_flag				*flag;
}						t_data;

ssize_t					ft_find_ants(char **line, int fd, t_data *data);
void					ft_ants_flag(t_data *data);
int						ft_print_ants(char **ways, t_data *data);
void					ft_check_bonuse(t_data *data);
void					ft_colour_flag(char **ways, t_data *data);
void					ft_len_flag(t_ways *ways, t_road *head);
void					ft_help_flag(t_data *data);
void					ft_ways_flag(t_ways *ways, t_data *data);
void					ft_help(t_data *data);
void					ft_read_flags(int ar, char **a, t_flag *f, t_data *d);
t_flag					*ft_create_flag(t_flag *flag);
int						ft_check_room(t_room *ro, char *na, int x, int y);
void					ft_start_end_error(char *line, int *se, t_data *data);
char					*ft_make_str(char *str, t_ways *ways);
void					ft_del_last_lst(t_ways *ways);
void					ft_sort_ants(char *str, t_data *data);
void					ft_del_road(t_road *road);
int						ft_print_error(int i, char *str, t_data *data);
void					ft_del_data(t_data **data);
void					ft_move_ants(t_ways *ways, t_data *data);
void					ft_sort_ways(t_ways *ways);
void					ft_set_ants(t_data *data, t_ways *ways);
t_road					*ft_create_road(t_road *road);
char					*ft_find_name(t_room *room, int ind);
int						ft_find_index(t_room *room, char *name);
void					ft_find_ways(t_data *data, t_room *room, t_ways *ways);
t_ways					*ft_create_ways(t_ways *ways);
void					ft_search_distance(t_data *data, t_room *room);
t_data					*ft_create_data(t_data *data);
int						ft_find_ind(char *name, t_room *room, t_data *data);
int						ft_check_arr_len(char **arr);
int						**ft_make_matrix(int **matrix, int len, int num);
int						ft_check_room_len(t_room *room);
void					ft_add_rooms(char *li, int *se, t_data *da, t_room *ro);
int						ft_check_strdigit(char *arr);
t_room					*ft_create_room(t_room *room);
int						ft_room_error(char *line, t_data *data);
char					**ft_link_error(char **line, int fd, t_data *data);
t_room					*ft_read(char *line, t_data *data);

#endif
