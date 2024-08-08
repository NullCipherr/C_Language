// Ponteiro para Ponteiro
//
// Ponteiro para ponteiro é um ponteiro que aponta para outro ponteiro.
// É util quando um ponteiro não é suficiente para apontar para um objeto, devido a complexidade do objeto.
// Exemplo: Matriz, Funções que retornam ponteiro para ponteiro, etc.
//
// Sintaxe: int **ptr;

#include <stdio.h>

void modificarPonteiro(int **ptr)
{
    int x = 10; // x é uma variável local.
    *ptr = &x;  // ptr é um ponteiro para ponteiro.
}

int main()
{
    int x = 5;
    int *ptr = &x; // ptr é um ponteiro para x

    printf("Valor de x antes da modificação: %d\n", x);
    printf("Endereço de x antes da modificação: %p\n", (void *)&x); // %p é usado para imprimir endereços de memória.

    modificarPonteiro(&ptr);

    printf("Valor de x depois da modificação: %d\n", x);
    printf("Endereço de x depois da modificação: %p\n", (void *)&x); // %p é usado para imprimir endereços de memória.
    printf("Valor apontado por ptr depois da modificação: %d\n", *ptr);

    return 0;
}