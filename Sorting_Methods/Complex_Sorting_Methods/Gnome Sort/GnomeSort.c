#include <stdio.h>
#include <stdlib.h>

void gnomeSort(int array[], int size) {
    int index = 0;

    while (index < size) {
        if (index == 0) {
            index++;
        }
        if (array[index] >= array[index - 1]) {
            index++;
        } else {
            int temp = array[index];
            array[index] = array[index - 1];
            array[index - 1] = temp;
            index--;
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

    gnomeSort(array, arraySize);

    printf("Sorted Array:\n");
    for (int i = 0; i < arraySize; i++) {
        printf("%d   ", array[i]);
    }

    printf("\n\n");

    free(array);

    return 0;
}
