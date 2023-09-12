#include <stdio.h>
#include <stdlib.h>
#define SIZE 500000

void merge(int array[], int start, int middle, int end) 
{
    int start1 = start, start2 = middle + 1, auxStart = 0, size = end - start + 1 ;
    int *auxArray ;
    auxArray = (int*)malloc(size * sizeof(int)) ;

    	while (start1 <= middle && start2 <= end) 
    	{
        	if (array[start1] < array[start2]) 
        	{
            		auxArray[auxStart] = array[start1] ;
            		start1++ ;
        	} 
        	else 
        	{
            		auxArray[auxStart] = array[start2] ;
            		start2++ ;
        	}
        	
        	auxStart++ ;
    	}
	
	// If there are still elements in the first half
    	while (start1 <= middle) 
    	{  
        	auxArray[auxStart] = array[start1] ;
        	auxStart++ ;
        	start1++ ;
    	}

    	// If there are still elements in the second half
    	while (start2 <= end) 
    	{
        	auxArray[auxStart] = array[start2];
        	auxStart++;
        	start2++;
    	}

	// Move the elements back to the original array
    	for (auxStart = start; auxStart <= end; auxStart++) 
    	{    
        	array[auxStart] = auxArray[auxStart - start];
    	}
    
    	free(auxArray) ;
}

void mergeSort(int array[], int start, int end) 
{
    if (start < end) 
    {
        int middle = (end + start) / 2 ;

        mergeSort(array, start, middle) ;
        mergeSort(array, middle + 1, end) ;
        merge(array, start, middle, end) ;
    }
}

int main() 
{
    int array[SIZE], i = 0, x = 0 ;
    
    // Randomize values in the array
    for (x = 0; x < SIZE; x++) 
    {
        array[x] = rand() ;
    }
    
    mergeSort(array, 0, SIZE-1) ;
    
    for (i = 0; i < SIZE; i++) 
    {
        printf("\n A(%d): %d", i + 1, array[i]) ;
    }
    
    return 0 ;    
}
