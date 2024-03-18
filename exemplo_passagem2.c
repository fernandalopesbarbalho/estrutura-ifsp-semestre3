#include <stdio.h>

int main(void) {
	int x, y, *p;
	y = 0;
	p = &y;
	x = *p;
	x = 4;
	(*p)++;
	--x;
	(*p) += x;
	printf("x: %d\n",x);
	printf("y: %d",y);
	
  return 0;
}
