/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 15:42:46 by bazuara           #+#    #+#             */
/*   Updated: 2020/01/13 14:16:52 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "src/lib/libft.h"

typedef	struct	s_flags
{
	int			is_minus;
	int			is_plus;
	int			is_space;
	int			is_zero;
	int			is_hash;
    int         is_num;
	int			is_point;
	int			decimals;
    int         width;
}				t_flags;

const char			*ft_printsymbol(const char *str, t_flags **flags, int **count);
//char			*ft_strnjoin(char const *s1, char const *s2, size_t n);
const char		*ft_checkflags(const char *str, int *count, t_flags *flags);
const char		*ft_printint(const char *str,va_list args, int **count,
				t_flags **flags);
int				ft_intlen(unsigned int n);


#endif
