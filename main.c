#include "ft_printf.h"
#include <stdio.h>

int main(void) {
	int res;
//           printf("sys: ");
//	       printf("test, %.i", 5); printf("\n");
			res = ft_printf("this %x number", 7562);
			ft_putstr_fd("\n counter: ", 1);
			ft_putnbr_fd(res, 1);
  return 0;
}
