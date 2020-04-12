/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:08:20 by eberta            #+#    #+#             */
/*   Updated: 2020/02/11 15:08:22 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void			print_map(t_map *map)
{
	int		i;

	i = 0;
	while (map->lines[i])
	{
		ft_putstr(map->lines[i]);
		ft_putchar('\n');
		i++;
	}
}

static char		**build_map(size_t map_size)
{
	char	**lines;
	size_t	i;

	if ((lines = (char**)malloc(sizeof(char*) * (map_size + 1))))
	{
		i = 0;
		while (i < map_size)
		{
			lines[i] = ft_strnew(map_size);
			ft_memset(lines[i], '.', map_size);
			i++;
		}
		lines[i] = NULL;
	}
	return (lines);
}

void			free_map(t_map **map)
{
	size_t	line;

	if (!map)
		return ;
	line = 0;
	while (line < (*map)->size)
		ft_strdel(&(*map)->lines[line++]);
	free((*map)->lines);
	(*map)->lines = NULL;
	free(*map);
	*map = NULL;
}

t_map			*create_map(size_t map_size)
{
	t_map	*map;

	if ((map = (t_map*)malloc(sizeof(t_map))))
	{
		if (!(map->lines = build_map(map_size)))
		{
			free(map);
			return (NULL);
		}
		map->size = map_size;
	}
	return (map);
}
