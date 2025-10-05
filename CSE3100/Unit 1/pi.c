#include <stdio.h>
#include <stdlib.h>

int main() {
    
    double calc_pi(int n);
	
    int n, i;

    
    
    printf("n = ");
    scanf("%d", &n);

    double pi = calc_pi(n);

    printf("PI = %.10f\n", pi);
    return 0;
}

double calc_pi(int n) {
    double num = 0;

    for(int i = 0; i <= n; i++) {
	double a = ( 4 / (double)(8 * i + 1));
        double b = ( 2 / (double)(8 * i + 4));
	double c = ( 1 / (double)(8 * i + 5)); 
	double d = ( 1 / (double)(8 * i + 6));
	double Q = a - b - c - d;
        double P = 1;
        for(int j = 0; j <= i; j++) {
            if(j == 0) {
                P = 1;
            } else {
                P *= 16;
            }
        }
        num += Q * (1/P);
    }
    return num;
}
