/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:13:03 by bazuara           #+#    #+#             */
/*   Updated: 2020/02/17 11:40:37 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_struct(t_flags *flags)
{
	printf("\n");
	printf("-----DEBBUG------\n");
	printf("is_minus: %i \n", flags->is_minus);
	printf("is_plus: %i \n", flags->is_plus);
	printf("is_space: %i \n", flags->is_space);
	printf("is_zero: %i \n", flags->is_zero);
	printf("is_num: %i \n", flags->is_num);
	printf("is_point: %i \n", flags->is_point);
	printf("precission: %zu \n", flags->precission);
	printf("width: %zu \n", flags->width);
}

static void	initialize_struct(t_flags *flags)
{
	flags->is_minus = 0;
	flags->is_plus = 0;
	flags->is_space = 0;
	flags->is_zero = 0;
	flags->is_num = 0;
	flags->is_point = 0;
	flags->precission = 0;
	flags->width = 0;
}

char		*ft_print_variable(char *str, va_list args, int *count,
		t_flags *flags)
{
	if (*str == 'i')
		str = (char *)ft_printint(str, args, &count, &flags);
	else if (*str == '%')
		str = (char *)ft_printsymbol(str, &flags, &count);
	else if (*str == 'c')
		str = (char *)ft_printchar(str, args, &count, &flags);
	else if (*str == 's')
		str = (char *)ft_printstring(str, args, &count, &flags);
	else if (*str == 'p')
		//str = (char *)ft_printpointer(str, args, &count, &flags);
		ft_putstr_fd("Todo: pointer", 1);
	else if (*str == 'd')
		//str = (char *)ft_printdecimal(str, args, &count, &flags);
		ft_putstr_fd("Todo: Decimals", 1);
	else if (*str == 'u')
		//str = (char *)ft_printunsigned(str, args, &count, &flags);
		ft_putstr_fd("Todo: Unsigned", 1);
	else if (*str == 'x')
		//str = (char *)ft_printminhex(str, args, &count, &flags);
		ft_putstr_fd("Todo: Min Hex", 1);
	else if (*str == 'X')
		//str = (char *)ft_printmaxhex(str, args, &count, &flags);
		ft_putstr_fd("Todo: Max Hex", 1);
	return (str);
}

int			ft_isflag(char *str)
{
	if (*str == '-' || *str == '+' || *str == ' ' ||
		(*str >= '0' & *str <= '9') || *str == '#' ||
		*str == '.')
		return (1);
	return (0);
}

int			ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	t_flags	flags;
	int		debug;

	debug = 0;
	count = 0;
	va_start(args, str);
	while (str && *str != '\0')
	{
		if (*str == '%')
		{
			initialize_struct(&flags);
			str++;
			if (ft_isflag((char *)str) == 1)
			{
				str = (char *)ft_checkflags((char *)str, &count, &flags);
				//ft_putstr_fd("lap", 1);
			}
			if (debug == 1)
				print_struct(&flags);
			str = (char *)ft_print_variable((char *)str, args, &count, &flags);
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
