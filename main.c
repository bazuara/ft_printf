#include "ft_printf.h"
#include <stdio.h>

int main(void) {
	int res;
//           printf("sys: ");
//	       printf("test, %.i", 5); printf("\n");
			res = ft_printf("%.*s", 3, "hello");
			ft_putstr_fd("\n counter: ", 1);
			ft_putnbr_fd(res, 1);
  return 0;
}
