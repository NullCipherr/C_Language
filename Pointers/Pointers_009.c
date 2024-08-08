// Ponteiros e Strings
//
// Strings em C são essencialmente arrays de caracteres terminados por um caractere nulo (\0).
// Ponteiros são frequentemente usados para manipular strings.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Função para imprimir uma string
void imprimirString(char *str)
{
    int n = 0; // Contador de caracteres

    // Enquanto não chegarmos ao final da string
    while (*str != '\0')
    {
        printf("Caracter %d : %c\n", n + 1, *str);
        str++; // Avançar para o próximo caractere
        n++;   // Incrementar o contador
    }
}

// Função para alterar uma string
void alterarString(char *str)
{
    // Alterando o primeiro caractere da string
    printf("\nAlterando a string, modificando o primeiro caractere para 'h'...\n");
    *str = 'h';
}

void alterarStringIndice(char *str, int indice, char novoCaracter)
{
    // Alterando o caractere na posição indice da string
    printf("\nAlterando o caractere na posição %d da string para '%c'...\n", indice, novoCaracter);
    str[indice] = novoCaracter;
}

void alterarStringIndice2(char *str, int indice, char novoCaracter)
{
    // Alterando o caractere na posição indice da string
    printf("\nAlterando o caractere na posição %d da string para '%c'...\n", indice, novoCaracter);
    *(str + indice) = novoCaracter;
}

// Função principal
int main()
{
    char str[] = "Hello, World!";

    // Imprimindo a string
    imprimirString(str);

    // Alterando a string
    alterarString(str);
    imprimirString(str);

    // Alterando o caractere na posição 7 da string
    alterarStringIndice(str, 7, 'X');
    imprimirString(str);

    // Alterando o caractere na posição 7 da string
    alterarStringIndice2(str, 7, 'Y');
    imprimirString(str);

    return 0;
}