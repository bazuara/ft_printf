/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 10:11:05 by bazuara           #+#    #+#             */
/*   Updated: 2020/03/31 19:46:10 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_printpointer(const char *str, va_list args, int **count,
		t_flags **flags)
{
	long int		i;
	unsigned int	abs;
	char			*hex;
	char			*temp;
	char			*filler;

	i = va_arg(args, long int);
	abs = (i < 0) ? -i : i;
	if ((((*flags)->has_precission == 1 && (*flags)->precission == 0) ||
				((*flags)->has_width == 1 && (*flags)->width == 0)) && (i == 0))
		hex = ft_strjoin("", "");
	else
		hex = ft_uitohex(i);
		//aplicar precission
	if ((*flags)->precission >= ft_strlen(hex) && (*flags)->precission > 0)
	{
		filler = ft_calloc((*flags)->precission - ft_strlen(hex) +
				1, sizeof(char));
		ft_memset(filler, '0', (*flags)->precission - ft_strlen(hex));
		temp = hex;
		hex = ft_strjoin(filler, temp);
		free(filler);
		free(temp);
	}
	temp = hex;
	hex = ft_strjoin("0x", temp);
	free(temp);
	//aplicar width
	if ((*flags)->width > ft_strlen(hex))
	{
		filler = ft_calloc((*flags)->width - ft_strlen(hex) + 1, sizeof(char));
		ft_memset(filler, ((*flags)->is_zero == 1 ? '0' : ' '),
				(*flags)->width - ft_strlen(hex));
		temp = hex;
		if ((*flags)->is_minus == 0)
			hex = ft_strjoin(filler, temp);
		else
			hex = ft_strjoin(temp, filler);
		free(filler);
		free(temp);
	}
	*(*(count)) += ft_strlen(hex);
	ft_putstr_fd(hex, 1);
	free(hex);
	str++;
	return (str);
}
