/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 11:07:33 by bazuara           #+#    #+#             */
/*   Updated: 2019/12/17 11:07:37 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void) {
  int res;
					ft_printf("sys: ");
           printf("%5i", -123); printf("\n");ft_printf("ft_: ");
  res = ft_printf("%5i", -123);
  return 0;
}
