/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:37:39 by bazuara           #+#    #+#             */
/*   Updated: 2020/01/13 17:57:10 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_printint(const char *str, va_list args, int **count,
		t_flags **flags)
{
	int i;
	int t;

	t = 0;
	i = va_arg(args, int);
	if ((*flags)->is_minus == 0 && (*flags)->width > 0)
		while (t < ((*flags)->width - ft_intlen(i)))
		{
			ft_putchar_fd((((*flags)->is_zero == 1) ? '0' : ' '), 1);
			(*(*count))++;
			t++;
		}
	if ((*flags)->is_plus == 1 && i >= 0)
	{
		ft_putchar_fd('+', 1);
		(*(*count))++;
	}
	ft_putnbr_fd(i, 1);
	(*(*count)) += ft_intlen(i);
	str++;
	if ((*flags)->is_minus == 1 && (*flags)->width > 0)
		while (t < ((*flags)->width - ft_intlen(i)))
		{
			ft_putchar_fd((((*flags)->is_zero == 1) ? '0' : ' '), 1);
			(*(*count))++;
			t++;
		}
	return (str);
}
