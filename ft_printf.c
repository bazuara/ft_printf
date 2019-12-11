/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:13:03 by bazuara           #+#    #+#             */
/*   Updated: 2019/12/11 13:05:52 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void print_struct(t_flags *flags)
{
	printf("-----DEBBUG------");
	printf("is_minus: %i \n", flags->is_minus);
	printf("is_plus: %i \n", flags->is_plus);
	printf("is_space: %i \n", flags->is_space);
	printf("is_zero: %i \n", flags->is_zero);
	printf("is_num: %i \n", flags->is_num);
	printf("width: %i \n", flags->width);
}

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

	int debug;
	debug = 0;

	count = 0;
	va_start(args, str);
	while (str && *str != '\0')
	{
		if (*str == '%')
		{
			str++;
			while (ft_isflag((char *)str) == 1)
				str = (char *)ft_checkflags((char *)str, &count, &flags);
			if (debug == 1)
				print_struct(&flags);
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
