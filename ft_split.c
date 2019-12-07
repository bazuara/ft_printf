/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:41:58 by bazuara           #+#    #+#             */
/*   Updated: 2019/11/21 11:50:07 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_count_words(char	const *s, char c)
{
	int	i;
	int w;
	int	state;

	i = 0;
	w = 0;
	state = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			state = 0;
		else if (state == 0)
		{
			state = 1;
			w++;
		}
		i++;
	}
	return (w);
}

static int		ft_nextwordlen(char const *s, char c, int i)
{
	int	l;

	l = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		l++;
	}
	return (l);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		w;
	int		k;
	char	**words;

	if (!s)
		return (0);
	w = ft_count_words(s, c);
	if (!(words = malloc(sizeof(char *) * (w + 1))))
		return (0);
	words[w] = 0;
	i = -1;
	j = 0;
	while (++i < w)
	{
		words[i] = malloc((sizeof(char) * ft_nextwordlen(s, c, j)) + 1);
		k = 0;
		while (s[j] == c && s[j] != '\0')
			j++;
		while (s[j] != c && s[j] != '\0')
			words[i][k++] = s[j++];
		words[i][k] = '\0';
	}
	return (words);
}
