#include <stdio.h>

void print_array (int x[]) {
	for (int i = 0; i < (sizeof(x)/sizeof(x[0])); i++) {
		printf("%d", x[i]);
	}
	printf("\n");
}
int main() {
	int arr[4] = {1, 2, 3, 4};
	print_array(arr);
}

