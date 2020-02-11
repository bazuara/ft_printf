/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:09:53 by bazuara           #+#    #+#             */
/*   Updated: 2020/02/11 12:34:30 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printword(char *word, t_flags **flags, int count)
{
	int c;
	size_t i;
	char nullstring[7];

	i = 0;
	c = count;
	ft_strlcpy(nullstring, "(null)", 7);
	if ((!word || *word == 0 )&& (*flags)->is_num == 1)
	{
		if ((*flags)->is_point == 1 && (*flags)->width > 0)
			while (i < 6 && i < (*flags)->width)
			{
				ft_putchar_fd(' ',1);
				i++;
			}
		else
			while (nullstring[i] != '\0' && (((*flags)->precission) == 0 || (i < ((*flags)->precission))))
			{
				ft_putchar_fd(nullstring[i], 1);
				i++;
				c++;
			}
			return (c);
	}
	if ((*flags)->precission == 0 && (*flags)->is_point == 1)
		return (c);
	//ft_putstr_fd("peta aqui",1);
	if ((*flags)->precission == 0)
		while ((word[i] != '\0'))
		{
			ft_putchar_fd(word[i], 1);
			i++;
			c++;
		}
	else
		while ((word[i] != '\0') && (*flags)->precission > i)
		{
			ft_putchar_fd(word[i], 1);
			i++;
			c++;
		}
	return (c);
}
