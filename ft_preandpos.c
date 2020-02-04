/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preandpos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:49:26 by bazuara           #+#    #+#             */
/*   Updated: 2020/02/04 15:59:29 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prespace(size_t width, size_t length, int count, char filler)
{
	int	t;
	int	dif;

	t = 0;
	//printf("debug preandpos length: %zu \n", length);
	//printf("debug preandpos width: %zu \n", width);
	dif = (int)width - (int)length;
	while ((t < (dif)) && (dif > 0))
	{
		ft_putchar_fd(filler, 1);
		//printf("pre t: %zu, width: %zu, length: %zu, count: %i dif: %i\n", t, width, length, count, dif);
		count++;
		t++;
	}
	return (count);
}

int	ft_posspace(size_t width, size_t length, int count, char filler)
{
	size_t	t;

	t = 0;
	//printf("debug preandpos length: %zu \n", length);
	//printf("debug preandpos width: %zu \n", width);
	while ((t < (width - length)) && ((int)length < (int)width))
	{
		ft_putchar_fd(filler, 1);
		//printf("pos t: %zu, width: %zu, length: %zu, count: %i dif: %i\n", t, width, length, count, ((int)length - (int)width));
		count++;
		t++;
	}
	return (count);
}	
