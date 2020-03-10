/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:11:05 by bazuara           #+#    #+#             */
/*   Updated: 2020/03/10 10:27:33 by bazuara          ###   ########.fr       */
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
	while (i <= (c / 2))
	{
		temp = str[i];
		str[i] = str[c - 1];
		str[c - 1] = temp;
		c--;
		i++;
	}
	return (str);
}

char		*ft_uitohex(unsigned long int q)
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


const char	*ft_printhex(const char *str, va_list args, int **count,
		t_flags **flags)
{
	long int		i;
	unsigned int	abs;
	char			*hex;
	char			*filler;



	(void)flags;
	i = va_arg(args, long int);
	abs = (i < 0) ? -i : i;
	//ft_putstr_fd(ft_uitohex(i), 1);
	//TODO rehacer el condicional
	if ((((*flags)->has_precission == 1 && (*flags)->precission == 0) || ((*flags)->has_width == 1 && (*flags)->width == 0)) && (i == 0))
		hex = ft_strjoin("", "");
	else
		hex = ft_strjoin("", ft_strrev(ft_uitohex(i)));
	//aplicar precission
	if ((*flags)->precission >= ft_strlen(hex) && (*flags)->precission > 0)
	{
		filler = ft_calloc((*flags)->precission - ft_strlen(hex) + 1, sizeof(char));
		ft_memset(filler, '0', (*flags)->precission - ft_strlen(hex));
		hex = ft_strjoin(filler, hex);
		free (filler);
	}
	//aplicar width
	if ((*flags)->width > ft_strlen(hex))
	{
		filler = ft_calloc((*flags)->width - ft_strlen(hex) + 1, sizeof(char));
		ft_memset(filler, ((*flags)->is_zero == 1 ? '0' : ' '), (*flags)->width - ft_strlen(hex));
		if ((*flags)->is_minus == 0)
			hex = ft_strjoin(filler, hex);
		else
			hex = ft_strjoin(hex, filler);
		free (filler);
	}
	if (*str == 'X')
		hex = ft_strtoupper(hex);
	*(*(count)) += ft_strlen(hex);
	ft_putstr_fd(hex, 1);
	str++;
	return (str);
}
