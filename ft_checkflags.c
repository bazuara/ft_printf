/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 11:49:01 by bazuara           #+#    #+#             */
/*   Updated: 2020/01/08 12:18:53 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/lib/libft.h"
#include "ft_printf.h"

static int	ft_intlen(unsigned int n)
{
	if (n < 10)
		return (1);
	else
		return (ft_intlen(n / 10) + 1);
}

const char		*ft_checkflags(const char *str, int *count, t_flags *flags)
{
	if (*str == '-')
	{
		flags->is_minus = 1;
		str++;
		(*count)++;
	}
	else if (*str == '+')
	{
		flags->is_plus = 1;
		str++;
		(*count)++;
	}
	else if (*str == ' ')
	{
		flags->is_space = 1;
		str++;
		//(*count)++;
	}
	else if (*str == '.')
	{
		flags->is_point = 1;
		str++;
		(*count)++;
		if (ft_isdigit(*str) == 1 && (*str != '0'))
		{
			flags->decimals = ft_atoi(str);
			(*count) = (*count) + (ft_atoi(str));
			str += ft_intlen(ft_atoi(str));
		}
	}
	if (*str == '0')
	{
		flags->is_zero = 1;
		str++;
		(*count)++;
	}
	else if (ft_isdigit(*str) == 1 && (*str != '0'))
	{
		flags->is_num = 1;
		flags->width = ft_atoi(str);
		(*count) = (*count) + (ft_atoi(str));
		//printf("longitud del int %i", (ft_intlen(ft_atoi(str))));
		str += ft_intlen(ft_atoi(str));
	}
	return (str);
}
