#include <stdlib.h>
#include <stdio.h>

// Function to find the position of the smallest element in an array
int findSmallestPosition(int array[], int start, int size) 
{
    int smallestPos = start, j ;

    for (j = start + 1; j < size; j++) 
    {
        if (array[j] < array[smallestPos]) 
        {
            smallestPos = j ;
        }
    }

    return smallestPos ;
}

// Function to swap two integers
void swap(int *a, int *b) 
{
    int temp = *a ;
    *a = *b ;
    *b = temp ;
}

// Function to perform selection sort
void selectionSort(int array[], int size) 
{
    int i, smallestPos ;

    for (i = 0; i < size - 1; i++) 
    {
        smallestPos = findSmallestPosition(array, i, size) ;
        swap(&array[i], &array[smallestPos]) ;
    }
}

int main() 
{
    int array[11] = {22, 34, 17, 38, 29, 15, 50, 18, 47, 13, 7}, i = 0 ;

    printf("\n*************SORTED ARRAY*************\n") ;

    selectionSort(array, 11) ;

    for (i = 0; i < 11; i++) 
    {
        printf("POS(%d): %d", i + 1, array[i]) ;
        printf("\n") ;
    }

    return 0 ;
}
