/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:09:53 by bazuara           #+#    #+#             */
/*   Updated: 2020/02/11 16:10:14 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_n_null(int n)
{
	char	nullstring[7];
	int		i;
	int		c;
	
	i = 0;
	c = 0;
	ft_strlcpy(nullstring, "(null)", 7);
	while (nullstring[i] != '\0' && i < n)
	{
		ft_putchar_fd(nullstring[i], 1);
		i++;
		c++;
	}
	return (c);
}

int		ft_printword(char *word, t_flags **flags, int count)
{
	int c;
	size_t i;

	i = 0;
	c = count;
	if ((!word || *word == '\0' || word == NULL) && ((*flags)->width > 0 || (*flags)->precission > 0))
	{
		if ((*flags)->is_point == 1 && (*flags)->width > 0)
		{
			while (i < 6 && i < (*flags)->width)
			{
				ft_putchar_fd(' ',1);
				i++;
			}
		}
		else
			c += ft_print_n_null((*flags)->precission);
	}
	else if ((*flags)->precission == 0 && (*flags)->is_point == 1)
		return (c);
	else if ((*flags)->precission == 0)
	{
		if (!word)
			c += ft_print_n_null(6);
		else
			while ((word[i] != '\0'))
			{
				ft_putchar_fd(word[i], 1);
				i++;
				c++;
			}
		}
	//else if ((*flags)->width > 0 && (*flags)->precission == 0)
	//	c += ft_print_n_null((*flags)->precission);
	else
		while ((word[i] != '\0') && (*flags)->precission > i)
		{
			ft_putchar_fd(word[i], 1);
			i++;
			c++;
		}
	return (c);
}
