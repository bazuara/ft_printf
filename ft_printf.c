/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:13:03 by bazuara           #+#    #+#             */
/*   Updated: 2019/12/10 12:09:46 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_variable(char *str, va_list args, int *count, t_flags *flags)
{
	if (*str == 'i')
	{
		str = (char *)ft_printint(str, args, &count, &flags);
	}
	else if (*str == '%')
	{
		ft_putchar_fd('%', 1);
		(*count)++;
		str++;
	}
	else if (*str == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		(*count)++;
		str++;
	}
	else if (*str == 's')
	{
		ft_putstr_fd(va_arg(args, char *), 1);
		(*count)++;
		str++;
	}
	return (str);
}

int		ft_isflag(char *str)
{
	if (*str == '-' || *str == '+' || *str == ' ' ||
		*str == '0' || *str == '#')
		return (1);
	return (0);
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
		if (*str == '%')
		{
			str++;
			while (ft_isflag((char *)str) == 1)
				str = (char *)ft_checkflags((char *)str, &count, &flags);
			str = ft_print_variable((char *)str, args, &count, &flags);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			str++;
			count++;
		}
	}
	va_end(args);
	return (count);
}
