/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:37:39 by bazuara           #+#    #+#             */
/*   Updated: 2020/04/11 19:34:58 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			max_int(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

char		*ft_strjoin_free(char *str1, char *str2, int i)
{
	char *temp;

	temp = ft_strjoin(str1, str2);
	if (i == 1)
		free(str1);
	else if (i == 2)
		free(str2);
	if (i == 3)
	{
		free(str1);
		free(str2);
	}
	return (temp);
}

const char	*ft_printint(const char *str, va_list args, int **count,
		t_flags **flags)
{
	int		i;
	int		abs;
	char	*num;
	char	*filler;

	i = va_arg(args, int);
	abs = ((i < 0) ? (-i) : (i));
	if (i == 0 && (*flags)->precission == 0 && (*flags)->has_precission == 1)
		num = ft_strjoin("", "");
	else
		num = ft_itoa(abs);
	//aplicar ceros de precission
	if ((*flags)->precission >= ft_strlen(num) && (*flags)->precission > 0)
	{
		filler = ft_calloc(max_int((*flags)->precission, (*flags)->width) -
				ft_strlen(num) + 1, sizeof(char));
		ft_memset(filler, '0', (*flags)->precission - ft_strlen(num));
		num = ft_strjoin_free(filler, num, 3);
	}
	//aplicar ceros de width
	if ((*flags)->width > ft_strlen(num) && (*flags)->is_zero == 1)
	{
		filler = ft_calloc((*flags)->width - ft_strlen(num) + 1, sizeof(char));
		ft_memset(filler, '0', (*flags)->width - ft_strlen(num));
		if ((*flags)->is_minus == 0)
			num = ft_strjoin_free(filler, num, 3);
		else
			num = ft_strjoin_free(num, filler, 3);
	}
	//aplicar el menos
	if (i < 0)
	{
		if (*num == '0' && (*flags)->width == ft_strlen(num))
			*num = '-';
		else if (*num != '-')
			num = ft_strjoin_free("-", num, 2);
	}
	//aplicar espacios
	if ((*flags)->width > ft_strlen(num))
	{
		filler = ft_calloc((*flags)->width - ft_strlen(num) + 1, sizeof(char));
		ft_memset(filler, ' ', (*flags)->width - ft_strlen(num));
		if ((*flags)->is_minus == 0)
			num = ft_strjoin_free(filler, num, 3);
		else
			num = ft_strjoin_free(num, filler, 3);
	}
	ft_putstr_fd(num, 1);
	(*(*count)) += ft_strlen(num);
	str++;
	free(num);
	return (str);
}
