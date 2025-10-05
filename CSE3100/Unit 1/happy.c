#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, h_num, sum;
	printf("n = ");
	scanf("%d", &n);
	h_num = n;
	while(n !=4) {
		sum = 0;
	
		do {
			int num = n%10;
			sum += (num * num);
			n = n/10;
		} while(n > 0);
		printf("%d\n", sum);
		if(sum == 1) {
			break;
		}
		n = sum;
	}
	if(sum == 1) printf("%d is a happy number.\n", h_num);
	else {
		printf("%d is NOT a happy number.\n", h_num);
	}
}
	
