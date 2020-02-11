/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preandpos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:49:26 by bazuara           #+#    #+#             */
/*   Updated: 2020/02/11 10:57:06 by bazuara          ###   ########.fr       */
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
	if (length == 0)
		t += 6;
	//printf("pre t: %i, width: %zu, length: %zu, count: %i dif: %i\n",
	//t, (*flags)->width, length, count, dif);
	if ((*flags)->is_point == 1)
		while ((t < dif) || (t <  ((int)(*flags)->width - (int)(*flags)->precission)))
		{
			ft_putchar_fd(filler, 1);
			//printf("pre t: %i, width: %zu, length: %zu, count: %i dif: %i\n",
			//t, (*flags)->width, length, count, dif);
			count++;
			t++;
		}
	else
		while ((t < dif) && (t <  ((int)(*flags)->width - (int)(*flags)->precission)))
		{
			ft_putchar_fd(filler, 1);
			//printf("pre t: %i, width: %zu, length: %zu, count: %i dif: %i\n",
			//t, (*flags)->width, length, count, dif);
			count++;
			t++;
		}

	return (count);
}

