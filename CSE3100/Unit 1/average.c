#include <stdio.h>

void main() {
	double x, average;
	double total = 0;
	int iter = 0;
	
	while(scanf("%lf", &x) == 1) {
		total += x;
		iter++;
		average = total/iter;
		printf("Total=%f Average=%f\n", total, average);
	}
}	
