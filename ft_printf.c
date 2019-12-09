/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:13:03 by bazuara           #+#    #+#             */
/*   Updated: 2019/12/09 12:27:16 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/lib/libft.h"
#include "ft_printf.h"

char	*ft_print_variable(char *str, va_list args, int *count)
{
	if (*str == 'i')
	{
		ft_putnbr_fd(va_arg(args, int), 1);
		str++;
	}
	else if (*str == '%')
	{
		ft_putchar_fd('%', 1);
		count++;
		str++;
	}
	else if (*str == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		count++;
		str++;
	}
	else if (*str == 's')
	{
		ft_putstr_fd(va_arg(args, char *), 1);
		count++;
		str++;
	}
	return (str);
}

int		ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	t_flags	flags;

	count = 0;
	va_start(args, str);
	while (str && *str != '\0')
	{
		ft_putchar_fd(*str, 1);
		str++;
		count++;
		if (*str == '%')
		{
			str++;
			str = ft_checkflags((char *)str, &count, &flags);
			str = ft_print_variable((char *)str, args, &count);
		}
	}
	va_end(args);
	return (count);
}
