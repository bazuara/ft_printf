/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preandpos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:49:26 by bazuara           #+#    #+#             */
/*   Updated: 2020/02/04 17:12:13 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prespace(t_flags **flags, size_t length, int count, char filler)
{
	int	t;
	int	dif;

	t = 0;
	//printf("debug pre length: %zu \n", length);
	//printf("debug pre width: %zu \n", (*flags)->width);
	dif = (int)(*flags)->width - (int)length;
	//printf("pre t: %i, width: %zu, length: %zu, count: %i dif: %i\n", t, (*flags)->width, length, count, dif);
	while (((t < (dif)) && (dif > 0)) || (t <  ((int)(*flags)->width - (int)(*flags)->decimals)))
	{
		ft_putchar_fd(filler, 1);
		//printf("pre t: %i, width: %zu, length: %zu, count: %i dif: %i\n", t, (*flags)->width, length, count, dif);
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
