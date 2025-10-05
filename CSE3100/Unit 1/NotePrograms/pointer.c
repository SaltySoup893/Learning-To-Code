#include <stdio.h>

void main() {
	int a = 10;
	int * ptr = &a;
	int * * ptr2 = &ptr;
	printf("A pointer is able to move back and forth using the & and * additions\n\t\t You can use an * to move 'foreward' through the line: ptr2 -> ptr -> a\n\t\t You can use an & to move 'backward' through the line: ptr2 <- ptr <- a\n");
	printf("a = %d\t&a = %p\nptr = %p\t&ptr = %p\t*ptr %d\nptr2 = %p\t&ptr = %p\t*ptr2 = %p\t**ptr2 = %d\n", a, &a, ptr, &ptr, *ptr, ptr2, &ptr2, *ptr2, **ptr2);
}
