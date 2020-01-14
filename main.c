#include "ft_printf.h"
#include <stdio.h>

int main(void) {
	int res;
//           printf("sys: ");
//	       printf("test, %.i", 5); printf("\n");
		   //ft_printf("ft_: ");
		   res = ft_printf("test:_%012.35s:_", "abcdefghijklm"); 
//		   printf("\nres: %i", res);
  return 0;
}
