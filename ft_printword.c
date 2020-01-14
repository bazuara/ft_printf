/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:09:53 by bazuara           #+#    #+#             */
/*   Updated: 2020/01/14 16:31:28 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printword(char *str, size_t length, int count)
{
	int c;
	size_t i;

	i = 0;
	c = count;
	while ((str[i] != '\0') && (length > i))
	{
		ft_putchar_fd(str[i], 1);
		i++;
		c++;
	}
	return (c);
}
