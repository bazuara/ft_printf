/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:37:39 by bazuara           #+#    #+#             */
/*   Updated: 2020/03/04 17:12:49 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		max_int(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

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
	if (i == 0 && (*flags)->precission == 0 && (*flags)->has_precission == 1)
		num = ft_strjoin("","");
	else
		num = ft_strjoin("", ft_itoa(abs));
	//aplicar ceros de precission
	//ft_putstr_fd("\n DEBUG 1", 1);
	if ((*flags)->precission >= ft_strlen(num) && (*flags)->precission > 0)
	{
		filler = ft_calloc(max_int((*flags)->precission, (*flags)->width) - ft_strlen(ft_itoa(abs)) + 1, sizeof(char));
		ft_memset(filler, '0', (*flags)->precission - ft_strlen(ft_itoa(abs)));
		num = ft_strjoin(filler, num);
		free (filler);
	}
	//aplicar ceros de width
	//ft_putstr_fd("\n DEBUG 2", 1);
	if ((*flags)->width > ft_strlen(num) && (*flags)->is_zero == 1)
	{
		filler = ft_calloc((*flags)->width - ft_strlen(num) + 1, sizeof(char));
		ft_memset(filler, '0', (*flags)->width - ft_strlen(num));
		if ((*flags)->is_minus == 0)
			num = ft_strjoin(filler, num);
		else
			num = ft_strjoin(num, filler);
		free (filler);
	}
	//aplicar el menos
	//ft_putstr_fd("\n DEBUG 3", 1);
	if (i < 0)
	{
		if (*num == '0' && (*flags)->width == ft_strlen(num))
			*num = '-';
		else 
			if (*num != '-')
				num = ft_strjoin("-", num);
	}
	//aplicar espacios
	//ft_putstr_fd("debug ft_strlen(num):", 1);
	//ft_putnbr_fd(ft_strlen(num), 1);
	//ft_putstr_fd("\n DEBUG 4", 1);
	if ((*flags)->width > ft_strlen(num))
	{
		filler = ft_calloc((*flags)->width - ft_strlen(num) + 1, sizeof(char));
		ft_memset(filler, ' ', (*flags)->width - ft_strlen(num));
		if ((*flags)->is_minus == 0)
			num = ft_strjoin(filler, num);
		else
			num = ft_strjoin(num, filler);
		free (filler);
	}
	ft_putstr_fd(num, 1);
	(*(*count)) += ft_strlen(num);
	str++;
	free(num);
	return (str);
}
