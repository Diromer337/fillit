/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:08:11 by eberta            #+#    #+#             */
/*   Updated: 2020/02/11 15:08:12 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			get_next_point(t_point *point, char **map)
{
	if (!map)
		return (0);
	point->x = point->x + 1;
	while (map[point->y] != NULL)
	{
		while (map[point->y][point->x] != '\0')
		{
			if (map[point->y][point->x] == '.')
				return (1);
			point->x = point->x + 1;
		}
		point->y = point->y + 1;
		point->x = 0;
	}
	return (0);
}

int			fill_map(t_map *map, t_tetr_list *figures, t_point start)
{
	int		found;

	found = 0;
	if (!figures)
		return (1);
	while ((!(found = check_tetrimino(figures->tetrimino,
			map, start)) && get_next_point(&start, map->lines)))
		;
	if (!found)
		return (0);
	place_tetrimino(figures->tetrimino, map, start);
	if (!fill_map(map, figures->next, create_static_point(0)))
	{
		remove_tetrimino(figures->tetrimino, map);
		if (!get_next_point(&start, map->lines))
		{
			start.x = 0;
			start.y = 0;
			return (0);
		}
		return (fill_map(map, figures, start));
	}
	return (1);
}

int			fill(t_tetr_list *input_figures)
{
	t_map			*map;
	t_point			start;
	t_tetr_list		*head;
	size_t			map_size;

	map_size = 2;
	map = create_map(map_size);
	start = create_static_point(0);
	while ((head = input_figures) &&
				!fill_map(map, head, start))
	{
		free_map(&map);
		map_size++;
		map = create_map(map_size);
		start.x = 0;
		start.y = 0;
	}
	print_map(map);
	free_map(&map);
	free(map);
	return (1);
}

int			fillit(const char *file)
{
	t_tetr_list		*input_figures;

	if (!(input_figures = get_tetriminoes(file)))
		return (0);
	if (!fill(input_figures))
	{
		free_tetr_lst(&input_figures);
		free(input_figures);
		return (0);
	}
	free_tetr_lst(&input_figures);
	free(input_figures);
	return (1);
}
