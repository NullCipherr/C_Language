#include <stdio.h>
#include <stdlib.h>

void cocktailShakerSort(int array[], int size) {
    int swapped = 1;
    int start = 0;
    int end = size - 1;

    while (swapped) {
        swapped = 0;

        for (int i = start; i < end; i++) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = 1;
            }
        }

        if (!swapped) {
            break;
        }

        swapped = 0;
        end--;

        for (int i = end - 1; i >= start; i--) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = 1;
            }
        }

        start++;
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

    cocktailShakerSort(array, arraySize);

    printf("Sorted Array:\n");
    for (int i = 0; i < arraySize; i++) {
        printf("%d   ", array[i]);
    }

    printf("\n\n");

    free(array);

    return 0;
}
