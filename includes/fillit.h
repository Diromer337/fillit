/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:35:45 by eberta            #+#    #+#             */
/*   Updated: 2020/02/11 15:35:47 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "unistd.h"
# define BUF_SIZE 20

typedef struct			s_point
{
	int		x;
	int		y;
}						t_point;

typedef struct			s_tetrimino
{
	t_point *start;
	char	**form;
	int		width;
	int		height;
}						t_tetrimino;

typedef struct			s_tetr_list
{
	t_tetrimino			*tetrimino;
	struct s_tetr_list	*next;
}						t_tetr_list;

typedef struct			s_map
{
	size_t		size;
	char		**lines;
}						t_map;

int						solve(const char *file);
t_tetr_list				*get_tetriminoes(const char *file);
void					free_tetrimino(t_tetrimino **tetrimino);
int						valid_tetrimino(const char *form, t_point **points);
t_point					*create_point(int len);
t_tetrimino				*create_tetrimino(const char *form, const char id);
void					free_point(t_point **point);
int						tetrimino_add(t_tetr_list **head, t_tetr_list **tail,
											const char *tetrimino, int id);
int						fillit(const char *file);
int						check_tetrimino(t_tetrimino *tetrimino, t_map *map,
											t_point point);
void					place_tetrimino(t_tetrimino *tetrimino, t_map *map,
											t_point point);
void					remove_tetrimino(t_tetrimino *tetrimino, t_map *map);
void					print_map(t_map *map);
t_map					*create_map(size_t map_size);
void					free_minmax_points(t_point **points);
void					free_map(t_map **map);
t_point					create_static_point(int len);
void					free_tetr_lst(t_tetr_list **head);
#endif
