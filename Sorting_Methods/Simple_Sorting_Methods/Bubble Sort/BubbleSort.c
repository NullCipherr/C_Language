#include <stdio.h>
#include <stdlib.h>

// Function to swap two integers
void swap(int *x, int *y) 
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to perform bubble sort
void bubbleSort(int array[], int size) 
{
    int k, j;
    int isOrdered = 0;

    for (k = 1; k < size; k++) 
    {
        for (j = 0; j < size - k; j++) 
        {
            // Compare adjacent elements and swap if necessary
            if (array[j] > array[j + 1]) 
            {
                swap(&array[j], &array[j + 1]);
            }

            isOrdered = 0;

            // Check if the array is already sorted
            for (int l = j; l < size - k; l++) 
            {
                if (array[l] > array[l + 1]) 
                {
                    isOrdered = 1;
                    break;
                }
            }
            
            // If the inner loop didn't make any swaps, break
            if (isOrdered == 0) 
            {
                break;
            }
        }
    }
}

int main() 
{
    int arraySize = 0;
    int *array;

    printf("Enter the size of the array: ");
    scanf("%d", &arraySize);

    // Allocate memory for the array
    array = (int *)malloc(arraySize * sizeof(int));

    printf("------------Enter the array elements------------\n");
    for (int i = 0; i < arraySize; i++) 
    {
        printf("A[%d]: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("------------Original Array------------\n");
    for (int i = 0; i < arraySize; i++) 
    {
        printf("%d   ", array[i]);
    }

    printf("\n\n\n");

    // Perform bubble sort to sort the array
    bubbleSort(array, arraySize);

    printf("------------Sorted Array------------\n");
    for (int i = 0; i < arraySize; i++) 
    {
        printf("%d   ", array[i]);
    }

    printf("\n\n");

    // Free allocated memory
    free(array);

    return 0;
}

