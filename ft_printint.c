/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:37:39 by bazuara           #+#    #+#             */
/*   Updated: 2020/01/13 13:44:17 by bazuara          ###   ########.fr       */
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
	if ((*flags)->width > 0)
	{
		printf("\nDebug: width %i \n", (*flags)->width);
		printf("Debug: intlen %i \n", ft_intlen(i));
		while (t < ((*flags)->width - ft_intlen(i)))
		{
			ft_putchar_fd(' ', 1);
			t++;
		}
	}
	if ((*flags)->is_plus == 1 && i >= 0)
	{
		ft_putchar_fd('+', 1);
		(*(*count))++;
	}
	ft_putnbr_fd(i, 1);
	(*(*count)) += ft_intlen(i);
	str++;
	return (str);
}
