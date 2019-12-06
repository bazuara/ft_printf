/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:13:03 by bazuara           #+#    #+#             */
/*   Updated: 2019/12/06 21:56:38 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

char	*ft_print_variable(char *str, va_list args)
{
	if (*str == 'i')
	{
		ft_putnbr_fd(va_arg(args, int), 1);
		str++;
	}
	else if (*str == '%')
	{
		ft_putchar_fd('%', 1);
		str++;
	}
	else if (*str == 'd')
	{
		ft_putnbr_fd(va_arg(args, int), 1);
		str++;
	}
	else if (*str == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		str++;
	}
	else if (*str == 's')
	{
		ft_putstr_fd(va_arg(args, char *), 1);
		str++;
	}
	return (str);
}

int		ft_printf(const char *str , ...)
{
	va_list	args;

	va_start(args, str);
	while (str && *str != '\0')
	{
		ft_putchar_fd(*str, 1);
		str++;
		if(*str == '%')
		{
			str++;
			str = ft_print_variable((char *)str, args);
		}
	}
	va_end(args);
	return (0);
}
