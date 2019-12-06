/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:50:44 by bazuara           #+#    #+#             */
/*   Updated: 2019/11/25 13:56:12 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lend;
	size_t	lens;

	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (lens);
	if (dstsize < lend)
		lens += dstsize;
	else
		lens += lend;
	while (src[i] != '\0' && lend < dstsize - 1 && dst != src)
	{
		dst[lend] = src[i];
		i++;
		lend++;
	}
	dst[lend] = '\0';
	return (lens);
}
