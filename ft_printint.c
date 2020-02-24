/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:37:39 by bazuara           #+#    #+#             */
/*   Updated: 2020/02/24 12:32:11 by bazuara          ###   ########.fr       */
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
	num = ft_strjoin("", ft_itoa(abs));
	//cortar o alargar hasta la precision determinada
	//aplicar ceros antes
	//aplicar el menos
	//aplicar espacios

	


	if ((*flags)->precission >= ft_strlen(ft_itoa(i)))
	{
		filler = ft_calloc(max_int((*flags)->precission, (*flags)->width) - ft_strlen(ft_itoa(abs)) + 1, sizeof(char));
		ft_memset(filler, '0', (*flags)->precission - ft_strlen(ft_itoa(abs)));
		num = ft_strjoin(filler, num);
		free (filler);
	}
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
	if (i < 0)
		num = ft_strjoin("-", num);
	else if (ft_strlen(num) < (*flags)->precission)
		num = ft_strjoin("0", num);
	if ((*flags)->width > ft_strlen(num) && (*flags)->is_zero == 0)
	{
		if (i < 0)
		{
			filler = ft_calloc((*flags)->width - ft_strlen(num), sizeof(char));
			ft_memset(filler, ' ', (*flags)->width - ft_strlen(num) - 1);
		}
		else
		{
			filler = ft_calloc((*flags)->width - ft_strlen(num) + 1, sizeof(char));
			ft_memset(filler, ' ', (*flags)->width - ft_strlen(num));
		}
		num = ft_strjoin(filler, num);
		free (filler);
	}
	if ((*flags)->width > ft_strlen(num))
	{
		if ((*flags)->is_zero == 0)
		{
			filler = ft_calloc((*flags)->width - ft_strlen(num) + 1, sizeof(char));
			ft_memset(filler, ' ', (*flags)->width - ft_strlen(num));
			if ((*flags)->is_minus == 0)
				num = ft_strjoin(filler, num);
			else
				num = ft_strjoin(num, filler);
			free (filler);
		}
		else
		{
			//TODO comportamiento con flag is_zero == 1
		}
	}
	ft_putstr_fd(num, 1);
	(*(*count)) += ft_strlen(num);
	str++;
	free(num);
	return (str);
}
