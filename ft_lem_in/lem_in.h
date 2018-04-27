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

typedef struct			s_start
{
  	char			**first;
  	struct s_start	*next;
  	struct s_start	*prev;
}						t_start;

typedef struct			s_end
{
	char			**second;
  	struct s_end	*next;
 	struct s_end	*prev;
}						t_end;

typedef struct			s_data
{
	int	ants;
	int	**matrix;
  	int len;
	char *start;
	char *end;
}						t_data;

typedef struct			s_room
{
	char			*name;
	int				start;
	int				end;
	int				x;
	int				y;
	struct s_room	*next;
}						t_room;

t_end					*ft_create_end(t_end *end);
t_start					*ft_create_start(t_start *start);
int						ft_way(t_data *data, t_room *room);
t_data					*ft_create_data(t_data *data);
int						ft_find_ind(char *name, t_room *room);
void					ft_print_error(int i, char *str);
int						ft_check_arr_len(char **arr);
int						**ft_make_matrix(int **matrix, int len);
int						ft_check_room_len(t_room *room);
t_room					*ft_add_rooms(char *line, t_room *room);
int						ft_check_strdigit(char *arr);
t_room					*ft_create_room(t_room *room);
int						ft_room_error(char *line);
char					**ft_link_error(char *line, int fd);
t_room					*ft_read(char *line, t_room *room, t_data *data);

#endif
