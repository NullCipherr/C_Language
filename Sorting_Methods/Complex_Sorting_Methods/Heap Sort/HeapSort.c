#include <stdlib.h>
#include <stdio.h>
#define SIZE 500000

// Function to perform heapsort
void heapsort(int array[], int size) 
{
    int i = size / 2, parent, child, temp ;

    // Build a max heap
    while (1) 
    {
        if (i > 0) 
        {
            i-- ;
            temp = array[i] ;
        } 
        else 
        {
            size-- ;
            if (size <= 0)
            {
            	return ;
            }
            
            temp = array[size] ;
            array[size] = array[0] ;
        }

        parent = i ;
        child = i * 2 + 1 ;

        while (child < size) 
        {
            if ((child + 1 < size) && (array[child + 1] > array[child]))
            {
            	child++ ;
            }
            if (array[child] > temp) 
            {
                array[parent] = array[child] ;
                parent = child ;
                child = parent * 2 + 1 ;
            } 
            else 
            {
                break ;
            }
        }
        array[parent] = temp ;
    }
}

int main() 
{
    int array[SIZE], i ;

    // Initialize the array with random values
    for (i = 0; i < SIZE; i++) 
    {
        array[i] = rand() ;
    }

    // Perform heapsort to sort the array
    heapsort(array, SIZE) ;

    // Print the sorted array
    for (i = 0; i < SIZE; i++) 
    {
        printf("\nArray[%d]: %d", i + 1, array[i]) ;
    }

    return 0 ;
}
