/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:37:39 by bazuara           #+#    #+#             */
/*   Updated: 2020/04/14 16:52:37 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*applyprecissionzeroes_uint(char *num, t_flags **flags)
{
	char *filler;

	if ((*flags)->precission >= ft_strlen(num) && (*flags)->precission > 0)
	{
		filler = ft_calloc(max_int((*flags)->precission, (*flags)->width) -
				ft_strlen(num) + 1, sizeof(char));
		ft_memset(filler, '0', (*flags)->precission - ft_strlen(num));
		num = ft_strjoin_free(filler, num, 3);
	}
	return (num);
}

char		*applywidthzeroes_uint(char *num, t_flags **flags)
{
	char *filler;

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

char		*applyminus_uint(char *num, long int i, t_flags **flags)
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

char		*applyspaces_uint(char *num, t_flags **flags)
{
	char *filler;

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

const char	*ft_printuint(const char *str, va_list args, int **count,
		t_flags **flags)
{
	unsigned int			i;
	unsigned long long	int abs;
	char					*num;

	i = va_arg(args, long int);
	if (i < 0)
		abs = -i;
	else
		abs = i;
	if (i == 0 && (*flags)->precission == 0 && (*flags)->has_precission == 1)
		num = ft_strjoin("", "");
	else
		num = ft_uitoa(abs);
	num = applyprecissionzeroes_uint(num, flags);
	num = applywidthzeroes_uint(num, flags);
	num = applyminus_uint(num, i, flags);
	num = applyspaces_uint(num, flags);
	ft_putstr_fd(num, 1);
	(*(*count)) += ft_strlen(num);
	str++;
	free(num);
	va_end(args);
	return (str);
}
