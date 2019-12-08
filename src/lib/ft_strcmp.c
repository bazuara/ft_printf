/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:50:29 by bazuara           #+#    #+#             */
/*   Updated: 2019/11/21 13:21:33 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int count;

	count = 0;
	while (s1[count] != '\0' && s2[count] != '\0' &&
			s1[count] == s2[count])
		count++;
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}
