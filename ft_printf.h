/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 15:42:46 by bazuara           #+#    #+#             */
/*   Updated: 2020/02/27 13:51:19 by bazuara          ###   ########.fr       */
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
	int			is_asterisk;
	int			has_precission;
	size_t		precission;
	int			has_width;
    size_t      width;
}				t_flags;

const char		*ft_printsymbol(const char *str, t_flags **flags, int **count);
const char		*ft_checkflags_sym(const char *str, t_flags *flags);
const char		*ft_checkflags_num(const char *str, t_flags *flags);
char			*ft_uitoa(unsigned long long int n);
const char		*ft_printint(const char *str,va_list args, int **count,
				t_flags **flags);
int				ft_prespace(t_flags **flags, size_t length, int count,
				char filler);
int				ft_posspace(size_t width, size_t length, int count, char filler);
const char		*ft_printstring(const char *str, va_list args, int **count,
				t_flags **flags);
const char		*ft_printchar(const char *str, va_list args, int **count,
				t_flags **flags);
int				ft_printword(char *str, t_flags **flags, int count);
char			*ft_long_itoa(long int nbr);
const char		*ft_printuint(const char *str,va_list args, int **count,
				t_flags **flags);
int				max_int(int a, int b);


#endif
