/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:47:31 by bazuara           #+#    #+#             */
/*   Updated: 2019/11/14 18:20:56 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;

	if (!dst && !src && len > 0)
		return (0);
	s1 = (char *)src;
	s2 = (char *)dst;
	if (dst > src)
	{
		while (len--)
			s2[len] = s1[len];
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
