#include <stdio.h>
#include <stdlib.h>

void oddEvenSort(int array[], int size) {
    int sorted = 0;

    while (!sorted) {
        sorted = 1;

        for (int i = 1; i < size - 1; i += 2) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                sorted = 0;
            }
        }

        for (int i = 0; i < size - 1; i += 2) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                sorted = 0;
            }
        }
    }
}

int main() {
    int arraySize = 0;
    int *array;

    printf("Enter the size of the array: ");
    scanf("%d", &arraySize);

    array = (int *)malloc(arraySize * sizeof(int));

    printf("Enter the array elements:\n");
    for (int i = 0; i < arraySize; i++) {
        printf("V[%d]: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Original Array:\n");
    for (int i = 0; i < arraySize; i++) {
        printf("%d   ", array[i]);
    }

    printf("\n\n");

    oddEvenSort(array, arraySize);

    printf("Sorted Array:\n");
    for (int i = 0; i < arraySize; i++) {
        printf("%d   ", array[i]);
    }

    printf("\n\n");

    free(array);

    return 0;
}
