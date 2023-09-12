#include <stdio.h>
#include <stdlib.h>

// Function to perform radix sort
void radixSort(int array[], int size) 
{
    int i, exp = 1, max = array[0] ;
    int *tempArray ;

    tempArray = (int *)calloc(size, sizeof(int)) ;

    // Find the maximum value in the array
    for (i = 0; i < size; i++) 
    {
        if (array[i] > max)
        {
            max = array[i] ;
    	}
    }

    // Perform radix sort
    while (max / exp > 0) 
    {
        int bucket[10] = {0} ;
        
        for (i = 0; i < size; i++)
        {    
            bucket[(array[i] / exp) % 10]++ ;
        }
        for (i = 1; i < 10; i++)
        {
            bucket[i] += bucket[i - 1] ;
        }
        for (i = size - 1; i >= 0; i--)
        {
        	tempArray[--bucket[(array[i] / exp) % 10]] = array[i] ;
        }
    
        for (i = 0; i < size; i++)
        {
        	array[i] = tempArray[i];
        }
           
        exp *= 10 ;
    }

    free(tempArray) ;
}

int main() 
{
    int array[100], i ;

    // Initialize the array with random values
    for (i = 0; i < 100; i++) 
    {
        array[i] = rand() ;
    }

    // Perform radix sort to sort the array
    radixSort(array, 100) ;

    // Print the sorted array
    for (i = 0; i < 100; i++) 
    {
        printf("\nA[%d]: %d", i + 1, array[i]) ;
    }

    return 0 ;
}
