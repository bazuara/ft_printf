/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:13:03 by bazuara           #+#    #+#             */
/*   Updated: 2019/12/06 18:23:16 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib/libft.h"
#include "ft_printf.h"

char	*ft_print_variable(char *str, va_list args)
{
	char	*temp;
	
	temp = va_arg(args, char*);
	ft_putstr_fd(temp, 1);
	str++;
	return (str);
}

int	ft_printf(const char *str /*, ...*/)
{
	va_list	args;

	va_start(args, str);
	while (str && *str != '\0')
	{
		ft_putchar_fd(*str, 1);
		str++;
		if(*str == '%')
		{
			str++;
			str = ft_print_variable(str, args);
		}
	}
	va_end(args);
	return (0);
}
