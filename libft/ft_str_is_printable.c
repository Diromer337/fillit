/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 16:10:42 by eberta            #+#    #+#             */
/*   Updated: 2019/09/27 16:10:43 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_printable(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (ft_isprint(s[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}