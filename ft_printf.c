/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:13:03 by bazuara           #+#    #+#             */
/*   Updated: 2019/12/06 14:20:11 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib/libft.h"

int	ft_printf(const char *str /*, ...*/)
{
	while (str && *str != '\0')
	{
		ft_putchar_fd(*str, 1);
		str++;
		if(*str == '%')
		{
			str++;
			if(*str == 'd')
			{
				ft_putchar_fd('X', 1);
				str++;
			}
		}
	}
	return (0);
}
