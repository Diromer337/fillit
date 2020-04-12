/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetrimino.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:08:51 by eberta            #+#    #+#             */
/*   Updated: 2020/02/11 15:08:53 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int		valid_block(const char *figure, int len, int *sides)
{
	int		x;
	int		y;
	int		current_sides;

	x = len % 5;
	y = (len + 5) / 5;
	current_sides = 0;
	if (y > 0)
		y -= 1;
	if ((y - 1) >= 0 && figure[x + (y - 1) * 5] == '#')
		current_sides++;
	if ((y + 1) < 4 && figure[x + (y + 1) * 5] == '#')
		current_sides++;
	if ((x - 1) >= 0 && figure[x - 1 + y * 5] == '#')
		current_sides++;
	if ((x + 1) < 4 && figure[x + 1 + y * 5] == '#')
		current_sides++;
	if (current_sides)
		*sides += current_sides;
	return (current_sides ? 1 : 0);
}

static int		invalid_figure(t_point **points)
{
	if (!*points)
		free_minmax_points(points);
	return (0);
}

static void		set_minmax_points(t_point **points, int *max_x,
									int blocks, int len)
{
	*max_x = len % 5 > *max_x ? len % 5 : *max_x;
	if (blocks == 0 || blocks == 3)
		points[blocks == 0 ? 0 : 1] = create_point(len);
	else if (len % 5 < points[0]->x)
		points[0]->x = len % 5;
}

int				valid_tetrimino(const char *figure, t_point **points)
{
	int		len;
	int		blocks;
	int		sides;
	int		max_x;

	max_x = 0;
	blocks = 0;
	sides = 0;
	len = -1;
	while (figure[++len])
	{
		if (((len + 1) % 5 == 0 && figure[len] != '\n') ||
		(figure[len] != '\n' && figure[len] != '.' && figure[len] != '#'))
			return (invalid_figure(points));
		else if (figure[len] == '#')
		{
			if (blocks > 4 || !valid_block(figure, len, &sides))
				return (invalid_figure(points));
			set_minmax_points(points, &max_x, blocks++, len);
		}
	}
	if (!blocks || blocks != 4 || sides < 6)
		return (invalid_figure(points));
	points[1]->x = max_x > points[1]->x ? max_x : points[1]->x;
	return (1);
}
