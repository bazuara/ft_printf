/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:29:52 by bazuara           #+#    #+#             */
/*   Updated: 2020/02/13 13:51:48 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_printchar(const char *str, va_list args, int **count,
		t_flags **flags)
{
	char	c;
	size_t	i;

	i = 0;
	c = va_arg(args, int);
	if ((*flags)->width > 0 && (*flags)->is_minus == 0)
	{
		while (i < (*flags)->width-1)
			{
				ft_putchar_fd(' ', 1);
				i++;
				(*count)++;
			}
	}
	ft_putchar_fd(c, 1);
	(*count)++;
	str++;
	if ((*flags)->width > 0 && (*flags)->is_minus == 1)
		while (i < (*flags)->width-1)
			{
				ft_putchar_fd(' ', 1);
				i++;
				(*count)++;
			}
	return (str);
}
