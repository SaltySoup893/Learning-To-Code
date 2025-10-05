#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//TODO
//Implement the below function
//Simulate one particle moving n steps in random directions
//Use a random number generator to decide which way to go at every step
//When the particle stops at a final location, use the memory pointed to by grid to 
//record the number of particles that stop at this final location
//Feel free to declare, implement and use other functions when needed

void one_particle(int *** grid, int n)
{
	int x = 0;
	int y = 0;
	int z = 0;
	int grid_size = (2*n + 1);
	
	for (int i = 0; i < n; i++) {
		int r = rand() % 6;
		switch (r) {
			case 0:
				x--;
				break;
			case 1:
				x++;
				break;
			case 2:
				y++;
				break;
			case 3:
				y--;
				break;
			case 4:
				z++;
				break;
			case 5:
				z--;
				break;
		}
	}
	grid[x + n][y + n][z + n] += 1;
}

//TODO
//Implement the following function
//This function returns the fraction of particles that lie within the distance
//r*n from the origin (including particles exactly r*n away)
//The distance used here is Euclidean distance
//Note: you will not have access to math.h when submitting on Mimir
double density(int ***grid, int n, double r)
{
	int grid_size = (2*n + 1);
	double total_points = 0;
	double points_in_rn = 0;


	for(int x = 0; x < grid_size; x++) {
		for(int y = 0; y < grid_size; y++) {
			for(int z = 0; z < grid_size; z++) {
				int temp_x = x-n;
				int temp_y = y-n;
				int temp_z = z-n;
				double sq_rn = (r*n)*(r*n);
				double hyp = (temp_x*temp_x) + (temp_y*temp_y) + (temp_z*temp_z);
				if (hyp <= sq_rn) points_in_rn += grid[x][y][z];
				total_points += grid[x][y][z];
			}
		}
	}
	return ((double)points_in_rn)/((double)total_points); 
}

//use this function to print results
void print_result(int ***grid, int n)
{
    printf("radius density\n");
    for(int k = 1; k <= 20; k++)
    {
        printf("%.2lf   %lf\n", 0.05*k, density(grid, n, 0.05*k));
    }
}

//TODO
//Finish the following function
//See the assignment decription on Piazza for more details
void diffusion(int n, int m)
{
	//fill in a few line of code below
	int grid_size = (2*n + 1);


	int *** grid = (int***)calloc(grid_size, sizeof(int**));
	if (grid == NULL) {
		perror("Failed to allocate memory");
	}

	for (int i = 0; i < grid_size; i++) {
		grid[i] = (int**)calloc(grid_size, sizeof(int*));
		if (grid == NULL) {
			perror("Failed to allocate memory");
		}
		for (int j = 0; j < grid_size; j++) {
			grid[i][j] = (int*)calloc(grid_size, sizeof(int));
			if (grid[i][j] == NULL) {
				perror("Failed to allocate memory");
			}
		}
	}
	
	for(int i = 1; i<=m; i++) one_particle(grid, n);

	print_result(grid, n);
	//fill in some code below
	for (int i = 0; i < grid_size; i++) {
		for (int j = 0; j < grid_size; j++) {
			free(grid[i][j]);
		}
		free(grid[i]);
	}
	free(grid);
}

int main(int argc, char *argv[]) {	
	if(argc != 3)
	{
		printf("Usage: %s n m\n", argv[0]);
		return 0; 
	}
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);

	assert(n >= 1 && n <=50);
	assert(m >= 1 && m <= 1000000);
	srand(12345);
	diffusion(n, m);
	return 0;
}
