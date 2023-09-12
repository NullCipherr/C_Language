#include <stdio.h>
#include <stdlib.h>

// Function to perform shell sort
void shellSort(int *array, int size) 
{
    int i, j, h = 1, value ;

    // Calculate the initial value of 'h' using the Knuth sequence
    while (h < size) 
    {
        h = 3 * h + 1 ;
    }

    while (h > 0) 
    {
        // Start with the h-th element and use insertion sort
        for (i = h; i < size; i++) 
        {
            value = array[i] ;
            j = i ;

            // Move elements that are greater than 'value' by 'h' positions to the right
            while (j > h - 1 && value <= array[j - h]) 
            {
                array[j] = array[j - h] ;
                j = j - h ;
            }

            // Insert 'value' into its correct position
            array[j] = value ;
        }

        // Reduce 'h' using the Knuth sequence
        h = h / 3 ;
    }
}

int main() 
{
    int array[530000], i = 0, x = 0 ;

    // Randomize values in the array
    for (x = 0; x < 530000; x++) 
    {
        array[x] = rand() ;
    }

    // Perform shell sort to sort the array
    shellSort(array, 530000) ;

    // Print the sorted array
    for (i = 0; i < 300000; i++) 
    {
        printf("\n V(%d): %d", i + 1, array[i]) ;
    }

    return 0;
}
