/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:37:39 by bazuara           #+#    #+#             */
/*   Updated: 2020/02/13 16:38:16 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_printint(const char *str, va_list args, int **count,
		t_flags **flags)
{
	int 	i;
	char 	num[22];

	i = va_arg(args, int);
	if ((*flags)->width > 0)
		ft_memcpy(num, ft_itoa(i), (*flags)->width);
	else
		ft_memcpy(num, ft_itoa(i), 22);
	ft_putstr_fd(num, 1);
	(*(*count)) += ft_strlen(num);
	str++;
	return (str);
}
