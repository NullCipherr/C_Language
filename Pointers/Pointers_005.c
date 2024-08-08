// Ponteiros e Arrays
//
// Ponteiros e Arrays são intimamente relacionados. De fato, um array é um ponteiro constante para o primeiro elemento do array. Vamos considerar o seguinte exemplo:
//
// int arr[5] = {1, 2, 3, 4, 5};
// int *ptr = arr;
//
// Aqui, arr é um array de 5 inteiros. Quando declaramos int *ptr = arr;, ptr é um ponteiro para o primeiro elemento do array arr. Portanto, ptr aponta
// para arr[0]. Assim, ptr pode ser usado para acessar os elementos do array arr. Por exemplo, ptr[2] é equivalente a arr[2].

#include <stdio.h>

int main()
{
    int arr[5] = {1, 2, 3, 4, 5}; // Array de 5 inteiros
    int *ptr = arr;               // ptr é um ponteiro para o primeiro elemento do array arr

    // Acessando elementos do array usando ptr
    // Faça um loop para acessar todos os elementos do array
    for (int i = 0; i < 5; i++)
    {
        printf("Elemento %d: %d\n", i + 1, ptr[i]); // ptr[i] é equivalente a arr[i]
    }

    // Endereços de memória
    // Imprima os endereços de memória dos elementos do array
    for (int i = 0; i < 5; i++)
    {
        printf("Endereço de arr[%d]: %p\n", i, (void *)&arr[i]); // %p é usado para imprimir endereços de memória
    }

    // Imprima o endereço de memória armazenado em ptr
    printf("Endereço de ptr: %p\n", (void *)ptr); // %p é usado para imprimir endereços de memória

    return 0;
}
