/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 22:58:06 by bazuara           #+#    #+#             */
/*   Updated: 2020/04/12 22:59:47 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		ft_numtohex(int n)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	else if (n == 10)
		return ('a');
	else if (n == 11)
		return ('b');
	else if (n == 12)
		return ('c');
	else if (n == 13)
		return ('d');
	else if (n == 14)
		return ('e');
	else if (n == 15)
		return ('f');
	return (0);
}

char		*ft_strrev(char *str)
{
	int		c;
	int		i;
	char	temp;

	c = ft_strlen(str);
	i = 0;
	while (i < c)
	{
		temp = str[i];
		str[i] = str[c - 1];
		str[c - 1] = temp;
		c--;
		i++;
	}
	return (str);
}

char		*ft_uitohex(long long int q)
{
	char	*str;
	int		r;
	int		i;

	i = 0;
	str = ft_calloc(50, sizeof(char));
	if (q == 0)
		str[i] = '0';
	while (q != 0)
	{
		r = q % 16;
		q /= 16;
		str[i] = (ft_numtohex(r));
		i++;
	}
	ft_strrev(str);
	return (str);
}
