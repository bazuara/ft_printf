/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:04:20 by bazuara           #+#    #+#             */
/*   Updated: 2019/11/18 18:39:25 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!*needle)
		return ((char *)haystack);
	i = ft_strlen(needle);
	while (*haystack && len-- >= i)
	{
		if (*haystack == *needle && !ft_strncmp(haystack, needle, i))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
