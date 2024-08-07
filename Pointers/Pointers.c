// Ponteiros
//
// Um ponteiro é uma variável que armazena o endereço de outra variável. Em outras palavras, um ponteiro é uma variável que armazena o endereço de memória de outra variável.
// Em C, um ponteiro é declarado usando o operador * (asterisco).
// Por exemplo, int *p; declara um ponteiro p que pode apontar para um valor inteiro.
// - O operador & (e comercial) é utilizado para obter o endereço de memória de uma variável.
// - O operador * (asterisco) é utilizado para obter o valor de uma variável apontada por um ponteiro.
// - O operador * (asterisco) também é utilizado para declarar um ponteiro.

// Além disso, um ponteiro pode ser usado para acessar o valor de uma variável, bem como para modificar o valor de uma variável.
// Por exemplo, se p é um ponteiro para uma variável a, então *p é o valor de a e p é o endereço de a.

#include <stdio.h>

int main()
{
    int x = 10;
    int *ptr;

    // Atribuir o endereço de x ao ponteiro ptr
    ptr = &x;

    // Imprimir o valor de x
    printf("Valor de x: %d\n", x);

    // Imprimir o endereço de x
    printf("Endereço de x: %p\n", (void *)&x);

    // Imprimir o valor armazenado no endereço apontado por ptr
    printf("Valor apontado por ptr: %d\n", *ptr);

    // Modificar o valor de x usando o ponteiro
    *ptr = 20;

    // Imprimir o novo valor de x
    printf("Novo valor de x: %d\n", x);

    return 0;
}
