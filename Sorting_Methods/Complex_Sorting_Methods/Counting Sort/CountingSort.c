#include <stdio.h>

// Function to perform counting sort
void countingSort(int arr[], int size) 
{
    int max, min ;
    int i ;

    // Find the maximum and minimum values in the array
    max = arr[0] ;
    min = arr[0] ;

    for (i = 0; i < size; i++) 
    {
        if (arr[i] > max) 
	{
            max = arr[i] ;
        }
        if (arr[i] < min) 
	{
            min = arr[i] ;
        }
    }

    // Calculate the range of values in the array
    int range = max - min + 1 ;

    // Create count and output arrays
    int count[range] ;
    int output[size] ;

    // Initialize count array
    for (int i = 0; i < size; i++) 
    {
        count[arr[i] - min]++;
    }

    // Update count array to store the cumulative count
    for (int i = 1; i < range; i++) 
    {
        count[i] += count[i - 1] ;
    }

    // Build the output array by placing elements in their sorted order
    for (int i = size - 1; i >= 0; i--) 
    {
        output[count[arr[i] - min] - 1] = arr[i] ;
        count[arr[i] - min]-- ;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < size; i++) 
    {
        arr[i] = output[i] ;
    }
}

// Function to print an array
void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]) ;
    }

    printf("\n") ;
}

int main() 
{
    int size = 8 ;
    int arr[] = {4, 2, 2, 8, 3, 3, 1, 5} ;

    // Perform counting sort
    countingSort(arr, size) ;

    // Print the sorted array
    printArray(arr, size) ;

    return 0 ;
}
