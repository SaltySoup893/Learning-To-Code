// Do not modify starter code
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

void commonChars(char arr[][MAX_LEN], int n) {
  int common[26];
  for (int i = 0; i < 26; i++) {
    common[i] = true;
  }
  int found = 0;

  int * repeated = calloc(26, sizeof(int));



  for (int i = 0; i < n; i++) {

    int * temparr = calloc(26, sizeof(int));
    int j = 0;
    while(arr[i][j] != '\0') {
        for(int k = 0; k < 26; k++) {

            if ((int)arr[i][j] == k+97) {
              temparr[k] = 1;
            }
        }
        j++;
    }
    for (int i = 0; i < 26; i++) {
        if (temparr[i] == 1) {
            if(common[i] == false) {
                repeated[i] = 1;
                found = 1;
            } else {
                common[i] = false;
            }
        }
    }
    free(temparr);
  }

  printf("Common characters: ");
  for (int i = 0; i < 26; i++) {
    if(repeated[i] == 1) {
        printf("%c ", i+97);
    }
  }
  if (!found) {
    printf("None");
  }
  printf("\n");
  free(repeated);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s string1 string2 ...\n", argv[0]);
    return 1;
  }

  int n = argc - 1;
  char arr[n][MAX_LEN];

  for (int i = 0; i < n; i++) {
    strcpy(arr[i], argv[i + 1]);
  }

  commonChars(arr, n);

  return 0;
}
