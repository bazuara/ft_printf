/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:09:53 by bazuara           #+#    #+#             */
/*   Updated: 2020/02/12 13:33:22 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_n_null(int n, int ew, int minus)
{
	char	nullstring[7];
	int		i;
	int		c;
	
	i = 0;
	c = 0;
	ft_strlcpy(nullstring, "(null)", 7);
	if (minus == 0)
		while (ew > 0)
		{
			ft_putchar_fd(' ', 1);
			ew--;
			c++;
		}
	while (nullstring[i] != '\0' && i < n)
	{
		ft_putchar_fd(nullstring[i], 1);
		i++;
		c++;
	}
	if (minus == 1)
		while (ew > 0)
		{
			ft_putchar_fd(' ', 1);
			ew--;
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
	if (word != NULL && *word == '\0')
		c += ft_print_n_null(0, (*flags)->width, (*flags)->is_minus);
	else if(!word || word == NULL || *word == '\0')
	{
		if ((*flags)->precission > 0 && (*flags)->is_point == 0)
		{
			c += ft_print_n_null((*flags)->precission, 0, 0);
		}
		else if((*flags)->precission > 0 && (*flags)->is_point == 1)
		{
			c += ft_print_n_null((*flags)->precission, 0, 0);
		}
		else if ((*flags)->precission == 0 && (*flags)->is_point == 1)
		{
			while (i < (*flags)->width)
			{
				ft_putchar_fd(' ',1);
				i++;
				c++;
			}
		}
		else
		{
			c += ft_print_n_null(7, (*flags)->width - 6, (*flags)->is_minus);
		}
	}
	else if ((*flags)->precission == 0 && (*flags)->is_point == 0)
	{
		ft_putstr_fd(word, 1);
		c += ft_strlen(word);
	}
	else if ((*flags)->precission != 0)
	{
		while (i < (*flags)->precission && word[i] != '\0')
		{
			ft_putchar_fd(word[i], 1);
			i++;
			c++;
		}
	}
	return (c);
}
