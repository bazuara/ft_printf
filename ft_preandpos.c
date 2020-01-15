/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preandpos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:49:26 by bazuara           #+#    #+#             */
/*   Updated: 2020/01/15 11:44:59 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prespace(size_t width, size_t length, int count, char filler)
{
	size_t	t;

	t = 0;
	while ((t < (width - length)) && (width > length))
	{
		ft_putchar_fd(filler, 1);
		printf("t: %zu, width: %zu, length: %zu, count: %i\n", t, width, length, count);
		count++;
		t++;
	}
	return (count);
}	
