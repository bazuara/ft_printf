/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:09:53 by bazuara           #+#    #+#             */
/*   Updated: 2020/02/04 12:34:09 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printword(char *str, t_flags **flags, int count)
{
	int c;
	size_t i;

	i = 0;
	c = count;
	if (!str)
		return (c) ;
	//ft_putstr_fd(str, 1);
	//ft_putchar_fd(str[1], 1);
	if ((*flags)->decimals == 0 && (*flags)->is_point == 1)
		return (c);
	if ((*flags)->decimals == 0)
		while ((str[i] != '\0'))
		{
			ft_putchar_fd(str[i], 1);
			i++;
			c++;
		}
	else
		while ((str[i] != '\0') && (*flags)->decimals > i)
		{
			ft_putchar_fd(str[i], 1);
			i++;
			c++;
		}
	return (c);
}
