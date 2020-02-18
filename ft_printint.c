/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:37:39 by bazuara           #+#    #+#             */
/*   Updated: 2020/02/18 16:27:36 by bazuara          ###   ########.fr       */
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
		abs = - i;
	else
		abs = i;
	num = ft_strjoin("", ft_itoa(abs));
	if ((*flags)->precission > 0)
	{
		if ((*flags)->precission < ft_strlen(ft_itoa(abs)))
			ft_memcpy(num, num, (*flags)->precission);
		else
		{
			filler = ft_calloc((*flags)->precission - ft_strlen(ft_itoa(abs)) + 1, sizeof(char));
			ft_memset(filler, '0', (*flags)->precission - ft_strlen(ft_itoa(abs)));
			num = ft_strjoin(filler, num);
			if (i < 0)
				num = ft_strjoin("-", num);
			free (filler);
		}
	}
	if ((*flags)->width > ft_strlen(ft_itoa(i)))
	{
		filler = ft_calloc((*flags)->width - ft_strlen(ft_itoa(i)) + 1, sizeof(char));
		ft_memset(filler, ' ', (*flags)->width - ft_strlen(ft_itoa(i)));
		if ((*flags)->is_minus == 0)
			num = ft_strjoin(filler, num);
		else
			num = ft_strjoin(num, filler);
	}
	else
		if (i < 0 && (*flags)->precission == 0)
			num = ft_strjoin("-", num);

	ft_putstr_fd(num, 1);
	(*(*count)) += ft_strlen(num);
	str++;
	free(num);
	return (str);
}
