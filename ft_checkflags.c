/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 11:49:01 by bazuara           #+#    #+#             */
/*   Updated: 2020/03/04 13:27:13 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/lib/libft.h"
#include "ft_printf.h"

size_t			ft_intlen(size_t n)
{
	if (n < 10)
		return (1);
	else
		return (ft_intlen(n / 10) + 1);
}
int			ft_isnum(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

const char		*ft_checkflags_sym(const char *str, va_list args, t_flags *flags)
{
	int i;
/*
	ft_putstr_fd("DEBUG current char: ", 1);
	ft_putchar_fd(*str, 1);
	ft_putstr_fd("DEBUG next char: ", 1);
	ft_putchar_fd(*(str + 1), 1);
	ft_putchar_fd('\n', 1);
*/
	if (*str == '0')
	{
		if (ft_isflag((char *)str - 1) == 0)
			flags->is_zero = 1;
	}
	if (*str == '-')
		flags->is_minus = 1;
	else if (*str == '+')
		flags->is_plus = 1;
	else if (*str == ' ')
		flags->is_space = 1;
	else if (*str == '.' && *(str + 1) == '*')
	{
		i = va_arg(args, int);
		if (i < 0)
		{
			flags->precission = -i;
			flags->is_minus = 1;
		}
		else
			flags->precission = i;
		flags->is_point = 1;
		flags->has_precission = 1;
		flags->is_zero = 0;
		str++;
	}
	else if (*str == '*')
	{
		i = va_arg(args, int);
		if (i < 0)
		{
			flags->width = -i;
			flags->is_minus = 1;
		}
		else
			flags->width = i;
		flags->is_num = 1;
		flags->has_width = 1;
	}
	str++;
	return (str);
}

const char		*ft_checkflags_num(const char *str, t_flags *flags)
{
	if (ft_isdigit(*str) == 1)
	{
		flags->is_num = 1;
		flags->width = ft_atoi(str);
		flags->has_width = 1;
		str += ft_strlen(ft_itoa(ft_atoi(str)));
	}
	if (*str == '.')
	{
		flags->has_precission = 1;
		flags->is_point = 1;
		str++;
		if (ft_isdigit(*str) == 1)
		{
			//check how to skip zeroes
			flags->precission = ft_atoi(str);
			while (*str >= '0' && *str <= '9')
				str++;
		//	str += ft_strlen(ft_itoa(ft_atoi(str)));
		}
		flags->is_zero = 0;
	}
	return (str);
}
