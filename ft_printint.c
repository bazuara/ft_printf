/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:37:39 by bazuara           #+#    #+#             */
/*   Updated: 2019/12/10 12:33:06 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_printint(const char *str,va_list args, int **count, t_flags **flags)
{
	int i;

	i = va_arg(args, int);
	//gestionar numeros que son espacios en blanco antes del int
	
	if ((*flags)->is_plus == 1 && i >= 0)
	{
		ft_putchar_fd('+', 1);
		(*(*count))++;
	}
	ft_putnbr_fd(i, 1);
	str++;
	return (str);
}
