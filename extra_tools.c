/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.co       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 20:25:07 by bazuara           #+#    #+#             */
/*   Updated: 2020/04/12 20:40:51 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			max_int(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

char		*ft_strjoin_free(char *str1, char *str2, int i)
{
	char *temp;

	temp = ft_strjoin(str1, str2);
	if (i == 1)
		free(str1);
	else if (i == 2)
		free(str2);
	if (i == 3)
	{
		free(str1);
		free(str2);
	}
	return (temp);
}

