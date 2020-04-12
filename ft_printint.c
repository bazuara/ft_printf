/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:37:39 by bazuara           #+#    #+#             */
/*   Updated: 2020/04/12 21:02:28 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*applypreczeroes(char *num, t_flags **flags)
{
	char	*filler;

	if ((*flags)->precission >= ft_strlen(num) && (*flags)->precission > 0)
	{
		filler = ft_calloc(max_int((*flags)->precission, (*flags)->width) -
				ft_strlen(num) + 1, sizeof(char));
		ft_memset(filler, '0', (*flags)->precission - ft_strlen(num));
		num = ft_strjoin_free(filler, num, 3);
	}
	return (num);
}

char		*applywidthzeroes(char *num, t_flags **flags)
{
	char	*filler;

	if ((*flags)->width > ft_strlen(num) && (*flags)->is_zero == 1)
	{
		filler = ft_calloc((*flags)->width - ft_strlen(num) + 1, sizeof(char));
		ft_memset(filler, '0', (*flags)->width - ft_strlen(num));
		if ((*flags)->is_minus == 0)
			num = ft_strjoin_free(filler, num, 3);
		else
			num = ft_strjoin_free(num, filler, 3);
	}
	return (num);
}

char		*applyminus(int i, char *num, t_flags **flags)
{
	if (i < 0)
	{
		if (*num == '0' && (*flags)->width == ft_strlen(num))
			*num = '-';
		else if (*num != '-')
			num = ft_strjoin_free("-", num, 2);
	}
	return (num);
}

char		*applyspaces(char *num, t_flags **flags)
{
	char	*filler;

	if ((*flags)->width > ft_strlen(num))
	{
		filler = ft_calloc((*flags)->width - ft_strlen(num) + 1, sizeof(char));
		ft_memset(filler, ' ', (*flags)->width - ft_strlen(num));
		if ((*flags)->is_minus == 0)
			num = ft_strjoin_free(filler, num, 3);
		else
			num = ft_strjoin_free(num, filler, 3);
	}
	return (num);
}

const char	*ft_printint(const char *str, va_list args, int **count,
		t_flags **flags)
{
	int		i;
	int		abs;
	char	*num;

	i = va_arg(args, int);
	abs = ((i < 0) ? (-i) : (i));
	if (i == 0 && (*flags)->precission == 0 && (*flags)->has_precission == 1)
		num = ft_strjoin("", "");
	else
		num = ft_itoa(abs);
	num = applypreczeroes(num, flags);
	num = applywidthzeroes(num, flags);
	num = applyminus(i, num, flags);
	num = applyspaces(num, flags);
	ft_putstr_fd(num, 1);
	(*(*count)) += ft_strlen(num);
	str++;
	free(num);
	return (str);
}
