#include <stdio.h>
#include <stdlib.h>

// Função para mesclar dois runs ordenados
void merge(int array[], int left[], int leftSize, int right[], int rightSize) {
    // Implemente a lógica de mesclagem aqui
}

// Função para ordenar um run com o Insertion Sort
void insertionSort(int array[], int size) {
    // Implemente o Insertion Sort aqui
}

// Função para dividir a sequência em runs e mesclá-los
void timSort(int array[], int size) {
    // Defina o tamanho mínimo de run, por exemplo, 32
    int minRun = 32;

    for (int i = 0; i < size; i += minRun) {
        int left = i;
        int right = (i + minRun - 1 < size - 1) ? (i + minRun - 1) : (size - 1);
        
        // Ordenar o run atual com o Insertion Sort
        insertionSort(array + left, right - left + 1);
    }

    int runSize = minRun;
    
    // Comece a mesclar os runs
    while (runSize < size) {
        for (int i = 0; i < size; i += 2 * runSize) {
            int left = i;
            int mid = (i + runSize - 1 < size - 1) ? (i + runSize - 1) : (size - 1);
            int right = (i + 2 * runSize - 1 < size - 1) ? (i + 2 * runSize - 1) : (size - 1);
            
            // Mesclar os runs atual e próximo
            merge(array + left, array + left, mid - left + 1, array + mid + 1, right - mid);
        }

        runSize *= 2;
    }
}

int main() {
    int size;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int *array = (int *)malloc(size * sizeof(int));
    
    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("V[%d]: ", i + 1);
        scanf("%d", &array[i]);
    }
    
    timSort(array, size);
    
    printf("Sorted Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d   ", array[i]);
    }
    
    printf("\n\n");
    
    free(array);
    
    return 0;
}
