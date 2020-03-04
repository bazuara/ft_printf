/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:09:53 by bazuara           #+#    #+#             */
/*   Updated: 2020/03/04 13:59:56 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_n_null(int n, int ew, int minus)
{
	char	nullstring[7];
	int		i;
	int		c;

	i = 0;
	c = 0;
	ft_strlcpy(nullstring, "(null)", 7);
	if (minus == 0 && ew > 0)
		while (ew-- > 0)
		{
			ft_putchar_fd(' ', 1);
			c++;
		}
	while (nullstring[i] != '\0' && i < n)
	{
		ft_putchar_fd(nullstring[i++], 1);
		c++;
	}
	if (minus == 1 && ew > 0)
		while (ew-- > 0)
		{
			ft_putchar_fd(' ', 1);
			c++;
		}
	return (c);
}

int	ft_putnchar(char c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
	return (i);
}

int	max_6(int i)
{
	if (i < 6)
		return (i);
	else
		return (6);
}

int	ft_putstr_len(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_printword(char *word, t_flags **flags, int count)
{
	size_t i;

	i = 0;
	if (word != NULL && *word == '\0')
		count += ft_print_n_null(0, (*flags)->width, (*flags)->is_minus);
	else if (!word || word == NULL || *word == '\0')
		if ((*flags)->precission > 0 && (*flags)->has_precission == 0)
			count += ft_print_n_null((*flags)->precission, 0, 0);
		else if ((*flags)->precission > 0 && (*flags)->has_precission == 1)
			count += ft_print_n_null((*flags)->precission, (*flags)->width
					- max_6((*flags)->precission), (*flags)->is_minus);
		else if ((*flags)->precission == 0 && (*flags)->has_precission == 1)
			count += ft_putnchar(' ', (*flags)->width);
		else
			count += ft_print_n_null(7, (*flags)->width - 6,
					(*flags)->is_minus);
	else if ((*flags)->precission == 0 && (*flags)->has_precission == 0)
		count += ft_putstr_len(word);
	else if ((*flags)->precission != 0)
		while (i < (*flags)->precission && word[i] != '\0')
		{
			ft_putchar_fd(word[i++], 1);
			count++;
		}
	return (count);
}
