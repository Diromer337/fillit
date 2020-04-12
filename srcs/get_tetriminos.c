/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:08:36 by eberta            #+#    #+#             */
/*   Updated: 2020/02/11 15:08:37 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int				valid_newlines(const char *tetrimino, int *flag)
{
	int		newlines;

	newlines = BUF_SIZE - 1;
	while (newlines > 0)
	{
		if (tetrimino[newlines] != '\n')
			return (-1);
		newlines -= 5;
	}
	if (tetrimino[BUF_SIZE] != '\n' && tetrimino[BUF_SIZE] != '\0')
		return (-1);
	if (tetrimino[BUF_SIZE] != '\0')
		*flag = 1;
	else
		*flag = 0;
	return (0);
}

t_tetr_list		*read_tetriminoes(int fd)
{
	char			tetrimino[BUF_SIZE + 1];
	int				n_tetrimino;
	int				flag;
	t_tetr_list		*head;
	t_tetr_list		*tail;

	n_tetrimino = 0;
	while (read(fd, ft_memset(tetrimino, '\0', BUF_SIZE + 1), BUF_SIZE + 1))
	{
		if (valid_newlines(tetrimino, &flag) == -1)
		{
			if (n_tetrimino != 0)
			{
				free_tetr_lst(&head);
				free(head);
			}
			return (NULL);
		}
		tetrimino[BUF_SIZE] = '\0';
		if (tetrimino_add(&head, &tail, tetrimino, n_tetrimino++) == -1)
			return (NULL);
	}
	if (n_tetrimino == 0 || flag == 1)
		return (NULL);
	return (head);
}

t_tetr_list		*get_tetriminoes(const char *file)
{
	int				fd;
	t_tetr_list		*input_figures;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	if (!(input_figures = read_tetriminoes(fd)))
	{
		close(fd);
		return (NULL);
	}
	close(fd);
	return (input_figures);
}
