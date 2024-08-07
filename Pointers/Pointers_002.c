// Passagem de Parâmetros por Referência
//
// Em C, os parâmetros de função são passados por valor por padrão. Isso significa que, podemos modificar o valor de um parâmetro dentro de uma função,
// porém a modificação não será refletida fora da função.
// No entanto, podemos passar um ponteiro como argumento para uma função, permitindo que a função modifique o valor da variável original.
// Isso é conhecido como passagem de parâmetros por referência.

#include <stdio.h>

// Função para incrementar o valor de uma variável
void incrementar(int *ptr)
{
    (*ptr)++; // Incrementa o valor apontado por ptr
}

// Função Principal
int main()
{
    int x = 10; // Declara uma variável inteira x e atribui o valor 10

    incrementar(&x); // Passa o endereço de x para a função incrementar
    printf("Valor de x após incrementar: %d\n", x);

    // Passa o endereço de x para a função incrementar novamente
    incrementar(&x);

    // Imprime o novo valor de x
    printf("Novo valor de x após incrementar novamente: %d\n", x);

    return 0;
}
