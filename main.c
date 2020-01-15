#include "ft_printf.h"
#include <stdio.h>

int main(void) {
	int res;
//           printf("sys: ");
//	       printf("test, %.i", 5); printf("\n");
		   //ft_printf("ft_: ");
		   res = ft_printf("%s%s" "test", "gavin"); 
//		   printf("\nres: %i", res);
  return 0;
}
