/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 15:42:46 by bazuara           #+#    #+#             */
/*   Updated: 2019/12/09 15:50:56 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "src/lib/libft.h"

typedef	struct	s_flags
{
	int			is_minus;
	int			is_plus;
	int			is_space;
	int			is_zero;
	int			is_hash;
}				t_flags;

char			*ft_strnjoin(char const *s1, char const *s2, size_t n);
char			*ft_checkflags(char *str, int *count, t_flags *flags);
char			*ft_printint(char *str,va_list args, int **count, t_flags **flags);

#endif
