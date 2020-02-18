#include "ft_printf.h"
#include <stdio.h>

int main(void) {
	int res;
//           printf("sys: ");
//	       printf("test, %.i", 5); printf("\n");
			res = ft_printf("%08.3i", 8375);
//		   printf("\nres: %i", res);
  return 0;
}
