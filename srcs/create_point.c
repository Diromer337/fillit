/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:07:32 by eberta            #+#    #+#             */
/*   Updated: 2020/02/11 15:07:35 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		free_point(t_point **point)
{
	if (!point || !*point)
		return ;
	free(*point);
	*point = NULL;
}

void		free_minmax_points(t_point **points)
{
	if (!points || !*points)
		return ;
	free_point(&points[0]);
	free_point(&points[1]);
	free(*points);
	*points = NULL;
}

t_point		create_static_point(int len)
{
	t_point		point;

	point.x = len % 5;
	point.y = (len + 5) / 5;
	if (point.y > 0)
		point.y -= 1;
	return (point);
}

t_point		*create_point(int len)
{
	t_point		*point;

	if ((point = (t_point*)malloc(sizeof(t_point))))
	{
		point->x = len % 5;
		point->y = (len + 5) / 5;
		if (point->y > 0)
			point->y -= 1;
	}
	return (point);
}
