#include <stdio.h>

void bubbleSort(int numList[], int size);
void printArray(int array[], int size);

void main() {
    int arraySize, i = 0;

    printf("This is the Bubblesort test program,\nHow many elements will be in the array?\n");
    scanf("%d", &arraySize);

    int array[arraySize];

    for(int i = 0; i < arraySize; i++) {

        switch(i+1) {
            case (1):
                printf("What will the 1st number be?\n");
                break;

            case (2):
                printf("What will the 2nd number be?\n");
                break;

            case (3):
                printf("What will the 3rd number be?\n");
                break;

            default:
                printf("What will the %dth number be?\n", i+1);

        }
        scanf("%d", &array[i]);

    }
    bubbleSort(array, arraySize);
    printf("After running your array through bubbleSort this is the result:\n");
    printArray(array, arraySize);
}

void bubbleSort(int numList[], int size) {

    for(int i = 0; i < size - 1; i++) {
       
        // True or False switch
        int swapped = 1;
        
        for(int j = 0; j < size - 1 - i; j++) {

            
            if(numList[j] > numList[j+1]) {

                int temp_num = numList[j+1];
                numList[j+1] = numList[j];
                numList[j] = temp_num;
                swapped = 0;
            }
        
        }

        if(swapped) break;
    }
}

void printArray(int array[], int size){
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
