#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* print out an error message and exit */
void my_error(char *s)
{
    perror(s);
    exit(1);
}

/* Concatnate two strings.
 * Dynamically allocate space for the result.
 * Return the address of the result.
 */
char *my_strcat(char *s1, char *s2)
{
	int s1_len = strlen(s1);
	int s2_len = strlen(s2);
    	int t_len = s1_len + s2_len + 1;


	char* s = (char *)malloc(sizeof(char) * t_len);

	if (s == NULL) {
		perror("Memory failed");
		return NULL;
	}
	
	strcpy(s, s1);

	strcat(s, s2);


	return s;
}

int main(int argc, char *argv[])
{
    	char    *s;

    	s = my_strcat("", argv[0]);

	for (int i = 1; i < argc; i ++) {
    		char *temp = my_strcat(s, argv[i]);
		free(s);
		s = temp;
		
		
    	}
	
    	printf("%s\n", s);
	if(s != NULL) {
		free(s);
		s = NULL;
	}

    	return 0;
}
