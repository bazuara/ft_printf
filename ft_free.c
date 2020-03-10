/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:10:22 by bazuara           #+#    #+#             */
/*   Updated: 2020/03/10 13:20:49 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_free(int i, ...)
{
	va_list	args;
	
	va_start(args, i);
	while (i < 0)
	free(va_arg(args, void*));
	va_end(args);	
}
