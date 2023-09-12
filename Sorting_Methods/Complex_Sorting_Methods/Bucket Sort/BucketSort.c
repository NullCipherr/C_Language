#include <stdio.h>

// Function to find the maximum value in an array
int getMax(int array[], int size)
{
  	int i, max ;
  	max = array[0] ;
  	
  	// Iterate through the array to find the maximum value
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i] ;
		}
	}
  
  	return max ;
}

// Function to perform bucket sort
void bucketSort(int array[], int size)
{
  	int bucket[15], i,j, max ; 
  	
  	// Find the maximum value in the array
  	max = getMax(array, size) ;
  	
  	// Initialize the bucket array to all zeros
  	for (i = 0; i <= max; i++)
  	{
    		bucket[i] = 0 ;
  	}
  	
  	// Count the occurrences of each element in the input array
  	for (i = 0; i < size; i++)
  	{
    		bucket[array[i]]++ ;
  	}
  	
  	// Reconstruct the sorted array from the bucket counts
  	for (i = 0, j = 0; i <= max; i++)
  	{
  		while (bucket[i] > 0)
    		{
      			array[j++] = i;
      			bucket[i]--;
    		}
  	}
}

// Function to print an array
void printArray(int array[], int size)
{
	int i;
  
  	for (i = 0; i < size; ++i)
  	{
    	printf("%d  ", array[i]);
  	}
  	printf("\n");
}

int main()
{
	// Initialize the data array with values
	int data[] = {4, 2, 3, 5, 6, 0, 9, 1, 16, 13,4, 2, 3, 5, 6, 0, 9, 1, 16, 13, 3,4, 2, 3, 5, 6, 0, 9, 1, 16, 13,4, 2, 3, 5, 6, 0, 9, 1, 16, 13, 3}, i;
  	int size = sizeof(data) / sizeof(data[0]);
  
  	// Perform bucket sort
  	bucketSort(data, size);
  	printf("\n");
  	
  	// Print the sorted array
  	printArray(data, size); // Sorted Array
  
  	return 0;
}
