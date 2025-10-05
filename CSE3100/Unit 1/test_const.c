#include <stdio.h>

void main() {
	int a = 10;
	const int * const pa = &a;
	printf("a = %d\t*pa = %d\t&a = %p\tpa = %p\n", a, *pa, &a, pa);
	a = 15;
	printf("a = %d\t*pa = %d\t&a = %p\tpa = %p\n", a, *pa, &a, pa);
	/*
	*pa = 20;
	printf("a = %d\t*pa = %d\t&a = %p\tpa = %p\n", a, *pa, &a, pa);
	*/
}
