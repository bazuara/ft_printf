/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 11:49:01 by bazuara           #+#    #+#             */
/*   Updated: 2020/04/14 18:59:27 by bazuara          ###   ########.fr       */
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

char			*loadasteriskprecission(va_list args, t_flags **flags,
		char *str)
{
	int i;

	i = va_arg(args, int);
	if (i < 0)
		(*flags)->has_precission = 0;
	else
	{
		(*flags)->precission = i;
		(*flags)->has_precission = 1;
	}
	(*flags)->is_zero = 0;
	return (str + 1);
}

void			loadasteriskwidth(va_list args, t_flags **flags)
{
	int i;

	i = va_arg(args, int);
	if (i < 0)
	{
		(*flags)->width = -i;
		(*flags)->is_minus = 1;
		(*flags)->is_zero = 0;
	}
	else
		(*flags)->width = i;
	(*flags)->is_num = 1;
	(*flags)->has_width = 1;
}

const char		*ft_checkflags_sym(const char *str, va_list args,
				t_flags *flags)
{
	if ((*str == '0') && (ft_isflag((char *)str - 1) == 0))
		flags->is_zero = 1;
	if (*str == '-')
		flags->is_minus = 1;
	else if (*str == '+')
		flags->is_plus = 1;
	else if (*str == ' ')
		flags->is_space = 1;
	else if (*str == '.' && *(str + 1) == '*')
		str = loadasteriskprecission(args, &flags, (char *)str);
	else if (*str == '*')
		loadasteriskwidth(args, &flags);
	str++;
	return (str);
}

const char		*ft_checkflags_num(const char *str, t_flags *flags)
{
	if (ft_isdigit(*str) == 1)
	{
		while (*str == '0' && ft_isdigit(*str) == 1)
			str++;
		flags->is_num = 1;
		flags->width = ft_atoi(str);
		flags->has_width = 1;
		str += ft_intlen(flags->width);
	}
	if (*str == '.')
	{
		flags->has_precission = 1;
		flags->is_point = 1;
		str++;
		if (ft_isdigit(*str) == 1)
		{
			flags->precission = ft_atoi(str);
			while (*str >= '0' && *str <= '9')
				str++;
		}
		flags->is_zero = 0;
	}
	return (str);
}
