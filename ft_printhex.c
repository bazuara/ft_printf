/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:11:05 by bazuara           #+#    #+#             */
/*   Updated: 2020/03/03 13:03:13 by bazuara          ###   ########.fr       */
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

char		*ft_uitohex(unsigned int q)
{
	char	*str;
	int		r;
	int		i;

	i = 0;
	str = ft_calloc(50, sizeof(char));
	if (q == 0)
		*str = '0';
	while (q != 0)
	{
		r = q % 16;
		q /= 16;
		*str = (ft_numtohex(r));
		str++;
		i++;
	}
	return (str - i);
}

char		*ft_strrev(char *str)
{
	int		c;
	int		i;
	char	temp;

	c = ft_strlen(str);
	i = 0;
	while (i <= ((c + 1) / 2))
	{
		temp = str[i];
		str[i] = str[c - 1];
		str[c - 1] = temp;
		c--;
		i++;
	}
	return (str);
}

const char	*ft_printhex(const char *str, va_list args, int **count,
		t_flags **flags)
{
	long int		i;
	unsigned int	abs;
	char			*hex;

	(void)flags;
	i = va_arg(args, long int);
	abs = (i < 0) ? -i : i;
	//ft_putstr_fd(ft_uitohex(i), 1);
	hex = ft_strjoin("", ft_strrev(ft_uitohex(i)));
	*(*(count)) += ft_strlen(hex);
	ft_putstr_fd(hex, 1);
	str++;
	return (str);
}
