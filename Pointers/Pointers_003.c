// Alocação Dinâmica de Memória
//
// Em C, a alocação dinâmica de memória é feita utilizando as funções
// - malloc()
// - calloc()
// - realloc()
// - free()
//
// Essas funções permitem alocar memória durante a execução do programa.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;  // Declara um ponteiro para um inteiro
    int n = 5; // Número de elementos no array

    // Alocar memória para um array de inteiros
    ptr = (int *)malloc(n * sizeof(int));

    if (ptr == NULL)
    {
        printf("Erro na alocação de memória\n");
        return 1;
    }

    // Inicializar o array
    for (int i = 0; i < n; i++)
    {
        ptr[i] = i * 2;
    }

    // Imprimir o array
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ptr[i]);
    }

    // Liberar a memória alocada
    free(ptr);

    return 0;
}