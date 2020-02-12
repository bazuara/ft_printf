/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preandpos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:49:26 by bazuara           #+#    #+#             */
/*   Updated: 2020/02/12 16:09:07 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prespace(t_flags **flags, size_t length, int count, char filler)
{
	int	t;
	int	dif;

	t = 0;
	dif = (int)(*flags)->width - (int)length;
	if (length == 0)
		t += 6;
	if ((*flags)->is_point == 1)
		while ((t < dif) || (t < ((int)(*flags)->width -
						(int)(*flags)->precission)))
		{
			ft_putchar_fd(filler, 1);
			count++;
			t++;
		}
	else
		while ((t < dif) && (t < ((int)(*flags)->width -
						(int)(*flags)->precission)))
		{
			ft_putchar_fd(filler, 1);
			count++;
			t++;
		}
	return (count);
}
