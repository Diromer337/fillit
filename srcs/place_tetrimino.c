/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetrimino.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:08:42 by eberta            #+#    #+#             */
/*   Updated: 2020/02/11 15:08:44 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			tetrimino_xshift(t_tetrimino *tetrimino)
{
	int		x_shift;

	x_shift = 0;
	while ((tetrimino->form)[0][x_shift] == '.')
	{
		x_shift++;
	}
	return (x_shift);
}

int			check_extension(t_tetrimino *tetrimino, t_map *map, t_point point)
{
	if ((point.y + tetrimino->height <= (int)map->size) &&
		(point.x - tetrimino_xshift(tetrimino) + tetrimino->width
		<= (int)map->size))
		return (1);
	return (0);
}

int			check_tetrimino(t_tetrimino *tetrimino, t_map *map, t_point point)
{
	int		x;
	int		y;
	char	**form;
	char	**lines;

	form = tetrimino->form;
	lines = map->lines;
	if (check_extension(tetrimino, map, point) != 1)
		return (0);
	y = 0;
	while (form[y] != NULL)
	{
		x = 0;
		while (form[y][x] != '\0')
		{
			if (!(lines[y + point.y][x - tetrimino_xshift(tetrimino)
					+ point.x] == '.' ||
					form[y][x] == '.'))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void		place_tetrimino(t_tetrimino *tetrimino, t_map *map, t_point point)
{
	int		x;
	int		y;
	char	**form;
	char	**lines;

	y = 0;
	form = tetrimino->form;
	lines = map->lines;
	while (form[y] != NULL)
	{
		x = 0;
		while (form[y][x] != '\0')
		{
			if (form[y][x] != '.')
			{
				lines[y + point.y][x - tetrimino_xshift(tetrimino) +
					point.x] = form[y][x];
			}
			x++;
		}
		y++;
	}
	tetrimino->start->x = point.x - tetrimino_xshift(tetrimino);
	tetrimino->start->y = point.y;
}

void		remove_tetrimino(t_tetrimino *tetrimino, t_map *map)
{
	int		x;
	int		y;
	char	**form;
	char	**lines;

	y = 0;
	form = tetrimino->form;
	lines = map->lines;
	while ((tetrimino->form)[y])
	{
		x = 0;
		while (form[y][x])
		{
			if (form[y][x] != '.')
			{
				lines[y + tetrimino->start->y][x + tetrimino->start->x] = '.';
			}
			x++;
		}
		y++;
	}
}
