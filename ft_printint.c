/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:37:39 by bazuara           #+#    #+#             */
/*   Updated: 2020/02/18 14:58:21 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_printint(const char *str, va_list args, int **count,
		t_flags **flags)
{
	int 	i;
	int		abs;
	char 	*num;
	char	*filler;

	i = va_arg(args, int);
	if (i < 0)
		abs = -i;
	else
		abs = i;
	num = ft_calloc(ft_intlen(abs) + 1, sizeof(char));
	ft_memcpy(num, ft_itoa(abs), ft_intlen(abs) + 1);
	if ((*flags)->precission > 0 )
	{
		if ((*flags)->precission < ft_intlen(abs))
			ft_memcpy(num, num, (*flags)->precission);
		else 
		{
			filler = ft_calloc((*flags)->precission + 1, sizeof(char));
			ft_memset(filler, '0', (*flags)->precission - ft_intlen(abs));
			num = ft_strjoin(filler, num);
			free (filler);
		}
	}
	if ((*flags)->width > ft_strlen(ft_itoa(abs)) && i < 0 && (*flags)->is_zero == 0)
		num = ft_strjoin("-", num);
	if ((*flags)->width > ft_intlen(abs))
		if ((*flags)->width > ft_strlen(num))
		{
			filler = ft_calloc((*flags)->width - ft_strlen(num) + 1, sizeof(char));
			ft_memset(filler, ((*flags)->is_zero == 1 ? '0' : ' '), (*flags)->width - ft_strlen(num));
			if ((*flags)->is_minus == 1)
				num = ft_strjoin(num, filler);
			else
				num = ft_strjoin(filler, num);
			free (filler);
		}
	if (i < 0)
	{
		if ((*flags)->width == 0 || (*flags)->width <= ft_strlen(ft_itoa(abs)))
			num = ft_strjoin("-", num);
		if ((*flags)->width > ft_strlen(ft_itoa(abs)) && (*flags)->is_zero == 1)
			num[0] = '-';

	}
	ft_putstr_fd(num, 1);
	(*(*count)) += ft_strlen(num);
	str++;
	free(num);
	return (str);
}
