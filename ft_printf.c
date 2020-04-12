/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:13:03 by bazuara           #+#    #+#             */
/*   Updated: 2020/04/12 22:33:13 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	initialize_struct(t_flags *flags)
{
	flags->is_minus = 0;
	flags->is_plus = 0;
	flags->is_space = 0;
	flags->is_zero = 0;
	flags->is_num = 0;
	flags->is_point = 0;
	flags->is_asterisk = 0;
	flags->has_precission = 0;
	flags->precission = 0;
	flags->has_width = 0;
	flags->width = 0;
}

char		*ft_print_variable(char *str, va_list args, int *count,
		t_flags *flags)
{
	if (*str == 'i' || *str == 'd')
		str = (char *)ft_printint(str, args, &count, &flags);
	else if (*str == '%')
		str = (char *)ft_printsymbol(str, &flags, &count);
	else if (*str == 'c')
		str = (char *)ft_printchar(str, args, &count, &flags);
	else if (*str == 's')
		str = (char *)ft_printstring(str, args, &count, &flags);
	else if (*str == 'p')
		str = (char *)ft_printpointer(str, args, &count, &flags);
	else if (*str == 'u')
		str = (char *)ft_printuint(str, args, &count, &flags);
	else if (*str == 'x' || *str == 'X')
		str = (char *)ft_printhex(str, args, &count, &flags);
	return (str);
}

int			ft_isflag(char *str)
{
	if (*str == '-' || *str == '+' || *str == ' ' ||
		(*str == '.' && *(str + 1) == '*') ||
		(*str == '0') || *str == '#' || *str == '*')
		return (1);
	return (0);
}

int			ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	t_flags	flags;

	count = 0;
	va_start(args, str);
	while (str && *str != '\0')
		if (*str == '%')
		{
			initialize_struct(&flags);
			str++;
			while (ft_isflag((char *)str) == 1)
				str = (char *)ft_checkflags_sym((char *)str, args, &flags);
			if (*str == '.' || (*str >= '0' && *str <= '9'))
				str = (char *)ft_checkflags_num((char *)str, &flags);
			str = (char *)ft_print_variable((char *)str, args, &count, &flags);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			str++;
			count++;
		}
	va_end(args);
	return (count);
}
