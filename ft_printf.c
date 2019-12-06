/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:13:03 by bazuara           #+#    #+#             */
/*   Updated: 2019/12/06 13:39:09 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib/libft.h"

int	ft_printf(const char *str /*, ...*/)
{
	ft_putstr_fd("prueba ", 7);
	ft_putstr_fd((char *)str, ft_strlen(str));
	return (0);
}
