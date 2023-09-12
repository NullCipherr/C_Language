#include <stdlib.h>
#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b) 
{
    int temp = *a ;
    *a = *b ;
    *b = temp ;
}

// Function to partition the array and return the pivot index
int partition(int arr[], int start, int end) 
{
    int i, pivotIndex = start ;

    for (i = start + 1; i <= end; i++) 
    {
        if (arr[i] < arr[start]) 
        {
            pivotIndex++ ;
            swap(&arr[i], &arr[pivotIndex]) ;
        }
    }

    swap(&arr[start], &arr[pivotIndex]) ;
    return pivotIndex ;
}

// Function to perform quicksort
void quickSort(int arr[], int start, int end) 
{
    if (start < end) 
    {
        int pivot = partition(arr, start, end) ;
        quickSort(arr, start, pivot - 1) ;
        quickSort(arr, pivot + 1, end) ;
    }
}

int main() 
{
    int array[11] = {22, 34, 17, 38, 29, 15, 50, 18, 47, 13, 7}, i = 0 ;

    //printf("\n************* SORTED ARRAY *************\n") ;

    quickSort(array, 0, 10) ;

    for (i = 0; i < 11; i++) 
    {
        printf("POS(%d): %d", i + 1, array[i]) ;
        printf("\n") ;
    }

    return 0;
}
