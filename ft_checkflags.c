/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 11:49:01 by bazuara           #+#    #+#             */
/*   Updated: 2020/02/24 16:52:30 by bazuara          ###   ########.fr       */
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

const char		*ft_checkflags(const char *str, int *count, t_flags *flags)
{
	(void)count;
	while (ft_isdigit(*str) == 0 && *str != '0')
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
	}
	if (ft_isdigit(*str) == 1)
	{
		flags->is_num = 1;
		flags->width = ft_atoi(str);
		flags->has_width = 1;
		str += ft_strlen(ft_itoa(ft_atoi(str)));
	}
	if (*str == '.')
	{
		//ft_putstr_fd("\nDebug str pre: ", 1);
		//ft_putchar_fd(*str, 1);
		flags->has_precission = 1;
		flags->is_point = 1;
		str++;
		//ft_putstr_fd("\nDebug str pos: ", 1);
		//ft_putchar_fd(*str, 1);
		//ft_putchar_fd('\n', 1);
		if (ft_isdigit(*str) == 1)
		{
			while (*str == '0')
				str++;
			flags->precission = ft_atoi(str);
			str += ft_strlen(ft_itoa(ft_atoi(str)));
		}
		flags->is_zero = 0;
	}
	return (str);
}
