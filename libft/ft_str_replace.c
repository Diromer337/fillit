/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:47:05 by eberta            #+#    #+#             */
/*   Updated: 2020/02/11 15:47:07 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_replace(char *str, char to_replace, char replace)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == to_replace)
			str[i] = replace;
		i++;
	}
}
