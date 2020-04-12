/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:07:54 by eberta            #+#    #+#             */
/*   Updated: 2020/02/11 15:07:55 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static void		fill_tetrimino(const char *form,
								const char id, t_tetrimino *new)
{
	int		x;
	int		y;

	y = 0;
	x = new->start->x + new->start->y * 5;
	while (y < new->height)
	{
		ft_memcpy(new->form[y], &form[x], new->width);
		ft_str_replace(new->form[y], '#', id);
		y++;
		x += 5;
	}
}

char			**create_form(int height, int width)
{
	char	**form;
	int		line;

	if ((form = (char**)malloc(sizeof(char*) * (height + 1))))
	{
		line = 0;
		while (line < height)
		{
			form[line] = ft_strnew(width);
			ft_memset(form[line], '.', width);
			line++;
		}
		form[line] = NULL;
	}
	return (form);
}

void			free_tetrimino(t_tetrimino **tetrimino)
{
	int		line;

	if (!tetrimino)
		return ;
	free_point(&((*tetrimino)->start));
	if ((*tetrimino)->form)
	{
		line = 0;
		while (line < (*tetrimino)->height)
		{
			ft_strdel(&((*tetrimino)->form[line]));
			line++;
		}
		free((*tetrimino)->form);
	}
	free(*tetrimino);
	*tetrimino = NULL;
}

t_tetrimino		*create_tetrimino(const char *form, const char id)
{
	t_tetrimino		*new;
	t_point			*points[2];

	if (!form)
		return (NULL);
	if (!valid_tetrimino(form, points))
		return (NULL);
	if ((new = (t_tetrimino*)malloc(sizeof(t_tetrimino))))
	{
		new->height = ((points[1])->y - (points[0])->y) + 1;
		new->width = ((points[1]->x) - (points[0])->x) + 1;
		new->start = points[0];
		free_point(&points[1]);
		new->form = create_form(new->height, new->width);
		fill_tetrimino(form, id, new);
	}
	return (new);
}
