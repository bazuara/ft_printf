/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:37:39 by bazuara           #+#    #+#             */
/*   Updated: 2020/02/17 13:02:19 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_printint(const char *str, va_list args, int **count,
		t_flags **flags)
{
	int 	i;
	char 	*num;
	char	*filler;
	char	plus[2];

	i = va_arg(args, int);
	plus[0] = '+';
	plus[1] = '\0';
	if ((*flags)->precission > 0)
	{
		if ((*flags)->precission < ft_strlen(ft_itoa(i)))
		{
			num = ft_calloc((*flags)->precission + 1, sizeof(char));
			ft_memcpy(num, ft_itoa(i), (*flags)->precission);
		}
		if ((*flags)->is_minus == 0)
			num = ft_strjoin(filler, num);
		else
			num = ft_strjoin(num, filler);
	}
	else
	{
		num = ft_calloc(ft_strlen(ft_itoa(i)) + 1, sizeof(char));
		ft_memcpy(num, ft_itoa(i), ft_strlen(ft_itoa(i)));
	}
	//TODO prepend y postpend spaces
	if ((*flags)->is_plus == 1 && i >= 0)
		num = ft_strjoin(plus, num);
	ft_putstr_fd(num, 1);
	(*(*count)) += ft_strlen(num);
	str++;
	return (str);
}
