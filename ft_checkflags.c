/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 11:49:01 by bazuara           #+#    #+#             */
/*   Updated: 2020/02/26 11:18:47 by bazuara          ###   ########.fr       */
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

const char		*ft_checkflags_sym(const char *str, t_flags *flags)
{
		if (*str == '-')
		{
			flags->is_minus = 1;
			str++;
		}
		if (*str == '+')
		{
			flags->is_plus = 1;
			str++;
		}
		if (*str == ' ')
		{
			flags->is_space = 1;
			str++;
		}
		if (*str == '0')
		{
			flags->is_zero = 1;
			str++;
		}
	/*if (ft_isdigit(*str) == 1)
	}*/
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
//			while (*str == '0')
//				str++;
			flags->precission = ft_atoi(str);
			str += ft_strlen(ft_itoa(ft_atoi(str)));
		}
		flags->is_zero = 0;
	}
	return (str);
}
