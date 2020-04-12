/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:13:18 by bazuara           #+#    #+#             */
/*   Updated: 2020/04/12 23:49:37 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_uintlength(unsigned long long int n)
{
	if (n < 10)
		return (1);
	else
		return (ft_uintlength(n / 10) + 1);
}

char	*ft_uitoa(unsigned long long int n)
{
	char	*str;
	int		len;

	len = ft_uintlength(n);
	str = ft_calloc(len + 1, sizeof(char));
	if (len == 0)
		return (0);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = n % 10 + '0';
		len--;
		n /= 10;
	}
	return (str);
}
