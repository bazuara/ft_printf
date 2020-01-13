#include "ft_printf.h"
#include <stdio.h>

int main(void) {
	int res;
//           printf("sys: ");
//	       printf("test, %.i", 5); printf("\n");
		   //ft_printf("ft_: ");
		   res = ft_printf("test_%125i", 135); 
		   //printf("res: %i", res);
  return 0;
}
