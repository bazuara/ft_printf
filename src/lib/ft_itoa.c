/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:54:16 by bazuara           #+#    #+#             */
/*   Updated: 2019/11/18 16:17:01 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strnew(int i)
{
	char	*str;

	if (!(str = malloc(i * sizeof(char))))
		return (0);
	else
		return (str);
}

static	int	ft_intlen(unsigned int n)
{
	if (n < 10)
		return (1);
	else
		return (ft_intlen(n / 10) + 1);
}

char		*ft_itoa(int nbr)
{
	char			*s;
	int				len;
	unsigned int	n;

	if (nbr < 0)
		n = -nbr;
	else
		n = nbr;
	len = ft_intlen(n);
	if (nbr < 0)
		len++;
	s = ft_strnew(len + 1);
	if (!s)
		return (0);
	s[len] = '\0';
	if (nbr < 0)
		s[0] = '-';
	while (((nbr < 0) ? 1 : 0) < len)
	{
		s[len - 1] = n % 10 + '0';
		len--;
		n /= 10;
	}
	return (s);
}
