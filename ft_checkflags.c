/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 11:49:01 by bazuara           #+#    #+#             */
/*   Updated: 2019/12/09 13:23:00 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/lib/libft.h"
#include "ft_printf.h"

char	*ft_checkflags(char *str, int *count, t_flags *flags)
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
		(*count)++;
	}
	else if (*str == '0')
	{
		flags->is_zero = 1;
		str++;
		(*count)++;
	}
	else if (*str == '#')
	{
		flags->is_hash = 1;
		str++;
		(*count)++;
	}
	return (str);
}
