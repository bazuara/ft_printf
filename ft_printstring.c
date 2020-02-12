/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:05:30 by bazuara           #+#    #+#             */
/*   Updated: 2020/02/12 10:56:06 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_printstring(const char *str, va_list args, int **count,
		t_flags **flags)
{
	char	*c;
	size_t 	t;

	t = 0;
	c = va_arg(args, char*);
	if ((*flags)->is_minus == 0 && (*flags)->width > 0)
		(*(*count)) = ft_prespace((&(*flags)), ft_strlen(c), *(*(count)), ' ');
	(*(*count)) = ft_printword(c, &(*flags), (*(*count)));
	if ((*flags)->is_minus == 1 && (*flags)->width > 0)
		(*(*count)) = ft_prespace((&(*flags)), ft_strlen(c), *(*(count)), ' ');
	str++;	
	return (str);
}
