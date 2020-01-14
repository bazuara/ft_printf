/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printsymbol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:12:09 by bazuara           #+#    #+#             */
/*   Updated: 2020/01/14 11:33:38 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_printsymbol(const char *str, t_flags **flags, int **count)
{
	size_t	t;

	t = 0;
	if ((*flags)->is_minus == 0 && (*flags)->width > 0)
		while (t < ((*flags)->width - 1))
		{
			ft_putchar_fd((((*flags)->is_zero == 1) ? '0' : ' '), 1);
			(*(*count))++;
			t++;
		}
	ft_putchar_fd('%', 1);
	(*(*count))++;
	str++;
	if ((*flags)->is_minus == 1 && (*flags)->width > 0)
		while (t < ((*flags)->width - 1))
		{
			ft_putchar_fd((((*flags)->is_zero == 1) ? '0' : ' '), 1);
			(*(*count))++;
			t++;
		}
	return (str);
}
