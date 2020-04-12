/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:08:29 by eberta            #+#    #+#             */
/*   Updated: 2020/02/11 15:08:30 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_tetr_list	*new_tetrimino(const char *str, int id)
{
	t_tetrimino		*new;
	t_tetr_list		*node;

	if (!(new = create_tetrimino(str, id)))
		return (NULL);
	node = (t_tetr_list*)malloc(sizeof(t_tetr_list));
	node->tetrimino = new;
	node->next = NULL;
	return (node);
}

void		free_tetr_lst(t_tetr_list **head)
{
	if (!head || !*head)
		return ;
	free_tetr_lst(&((*head)->next));
	free_tetrimino(&(*head)->tetrimino);
	free(*head);
	*head = NULL;
}

int			tetrimino_add(t_tetr_list **head, t_tetr_list **tail,
						const char *tetrimino, int id)
{
	if (id && ((*tail)->next = new_tetrimino(tetrimino, 'A' + id)))
		*tail = (*tail)->next;
	else if ((*head = new_tetrimino(tetrimino, 'A' + id)))
		*tail = *head;
	else
	{
		free_tetr_lst(head);
		return (-1);
	}
	return (0);
}
