#include <stdio.h>
#include <stdlib.h>

double two_d_random(int n)
{

	//Fill in code below
	//When deciding which way to go for the next step, generate a random number as follows.
	//r = rand() % 4;
	//Treat r = 0, 1, 2, 3 as up, right, down and left respectively.

	//The random walk should stop once the x coordinate or y coordinate reaches $-n$ or $n$. 
	//The function should return the fraction of the visited $(x, y)$ coordinates inside (not including) the square.
		
	int num = n;
	//printf("n = %d", num);	
	int **visited;
	visited = (int **)malloc(((2*n)-1)*sizeof(int *));
	
	for(int i = 0; i < (2*n)-1; i++) {
		visited[i] = (int *)malloc(((2*n)-1) * sizeof(int));
	}
	for(int i = 0; i< (2*n)-1; i++) {
		for(int j = 0; j < (n*2)-1; j++) {
			visited[i][j] = 0;
		}
	}	
	int num_visited = 0, edge_found = 0, x = 0, y = 0;
	while(!edge_found) {
		 if (y == n || y == -n || x == n || x == -n) {


                        double num = ((double)num_visited)/(double)(((2*n)-1) * ((2*n)-1));
                        for (int i = 0; i < (2*n)-1; i++) {
                                free(visited[i]);
                        }
                        free(visited);

                        return num;
                }


		if (visited[x+n-1][y+n-1] != 1) {
			visited[x+n-1][y+n-1] = 1;
			num_visited += 1;
		}
		int r = rand() % 4;
		switch (r)
		{
		case 0: //up
			y += 1;
			break;
		
		case 1: //right
			x += 1;
			break;

		case 2: //down
			y -= 1;
			break;
		
		case 3: // left
			x -= 1;
			break;
		}
	}	
}
/*
int main() {
	
	int n;
	while(scanf("%d", &n) == 1) {
		
		double sum = 0;
		for(int i = 0; i < 2; i++) {
			int num = n;
			sum = sum + two_d_random(num);
		}		
		printf("%d, %f, %f", n, sum, sum/2);
	}
	return 1;
}
*/

//Do not change the code below


int main(int argc, char *argv[])
{
	int trials = 1000;
	int i, n, seed;
	if (argc == 2) seed = atoi(argv[1]);
	else seed = 12345;

	srand(seed);
	for(n=1; n<=64; n*=2)
	{	
		double sum = 0.;
		for(i=0; i < trials; i++)
		{
			double p = two_d_random(n);
			sum += p;
		}
		printf("%d %.3f\n", n, sum/trials);
	}
	return 0;
}

