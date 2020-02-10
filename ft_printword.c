/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:09:53 by bazuara           #+#    #+#             */
/*   Updated: 2020/02/10 17:34:02 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printword(char *str, t_flags **flags, int count)
{
	int c;
	size_t i;
	char nullstring[7];

	i = 0;
	c = count;
	ft_strlcpy(nullstring, "(null)", 7);
	if (!str)
		ft_putstr_fd("entra en null",1 );
	{
		while (nullstring[i] != '\0' && (((*flags)->precission) == 0 || (i < ((*flags)->precission))))
		{
			ft_putchar_fd(nullstring[i], 1);
			i++;
			c++;
		}
		return (c);
	}
	if ((*flags)->precission == 0 && (*flags)->is_point == 1)
		return (c);
	if ((*flags)->precission == 0)
		while ((str[i] != '\0'))
		{
			ft_putchar_fd(str[i], 1);
			i++;
			c++;
		}
	else
		while ((str[i] != '\0') && (*flags)->precission > i)
		{
			ft_putchar_fd(str[i], 1);
			i++;
			c++;
		}
	return (c);
}
