#include "ft_printf.h"
#include <stdio.h>

int main(void) {
	int res;
//           printf("sys: ");
//	       printf("test, %.i", 5); printf("\n");
		   //ft_printf("ft_: ");
		   res = ft_printf("%.01s", "\0"); 
//		   printf("\nres: %i", res);
  return 0;
}
