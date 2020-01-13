/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printsymbol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:12:09 by bazuara           #+#    #+#             */
/*   Updated: 2020/01/13 12:24:45 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printsymbol(const char *str, int **count)
	{
			ft_putchar_fd('%', 1);
			(*(*count))++;
			str++;
			return (str);
	}
