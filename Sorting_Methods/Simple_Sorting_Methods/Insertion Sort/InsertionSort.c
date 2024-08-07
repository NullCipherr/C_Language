#include <stdio.h>
#include <stdlib.h>

// Function to perform insertion sort
void insertionSort(int array[], int size)
{
    int i, j, selectedNumber ;

    for (i = 1; i < size; i++)
    {
        selectedNumber = array[i] ; // Element selected from the array assumes the value of element 1
        j = i - 1 ; // j = 0

	// While j >= 0 and if element 0 is greater than the selected number
        while ((j >= 0) && (array[j] > selectedNumber))
        {
            array[j + 1] = array[j] ; // array[1] = array[0]
            j-- ; // j = 0
        }
        array[j + 1] = selectedNumber ; // array[1] = Selected Number (array[0])
    }
}

int main()
{
    int arraySize = 0 ;
    int *array ;

    printf("Enter the size of the array: ") ;
    scanf("%d", &arraySize) ;

    array = (int *)malloc(arraySize * sizeof(int)) ;

    printf("------------Enter the array elements------------\n") ;
    for (int i = 0; i < arraySize; i++)
    {
        printf("V[%d]: ", i + 1) ;
        scanf("%d", &array[i]) ;
    }

    printf("------------Original Array------------\n");
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d   ", array[i]) ;
    }

    printf("\n\n\n") ;

    // Perform insertion sort to sort the array
    insertionSort(array, arraySize) ;

    printf("------------Sorted Array------------\n") ;
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d   ", array[i]) ;
    }

    printf("\n\n") ;

    // Free allocated memory
    free(array) ;

    return 0 ;
}
