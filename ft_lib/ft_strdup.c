/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:14:22 by bazuara           #+#    #+#             */
/*   Updated: 2019/11/13 13:01:11 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*copy;

	i = ft_strlen(s1) + 1;
	if ((copy = malloc(i)))
	{
		ft_memcpy(copy, s1, i);
		return (copy);
	}
	return (0);
}
