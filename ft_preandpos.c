/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preandpos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:49:26 by bazuara           #+#    #+#             */
/*   Updated: 2020/01/14 12:04:51 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prespace(size_t width, int length, int count, char filler)
{
	size_t	t;

	t = 0;
	while (t < (width - (size_t)length))
	{
		ft_putchar_fd(filler, 1);
		count++;
		t++;
	}
	return (count);
}	
