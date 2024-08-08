// Ponteiros e Funções
//
// Ponteiros podem ser utilizados para passar funções como parametros para outras funções. Isso é conhecido como passagem de funções por referência.

#include <stdio.h>

// Função que imprime um inteiro
void imprimir(int n)
{
    printf("Valor: %d\n", n);
}

// Funções que realizam operações matemáticas

// Função que duplica um inteiro
void duplicar(int n)
{
    printf("O valor %d duplicado é igual a: %d\n", n, 2 * n);
}

// Função que triplica um inteiro
void triplicar(int n)
{
    printf("O valor %d triplicado é igual a: %d\n", n, 3 * n);
}

// Função que soma 10 a um inteiro
void somar(int n)
{
    printf("O valor %d somado com 10 é igual a: %d\n", n, n + 10);
}

// Função que subtrai 5 de um inteiro
void subtrair(int n)
{
    printf("O valor %d subtraído de 5 é igual a: %d\n", n, n - 5);
}

// Função que divide um inteiro por 2
void dividir(int n)
{
    printf("O valor %d dividido por 2 é igual a: %d\n", n, n / 2);
}

// Função que multiplica um inteiro por 3
void multiplicar(int n)
{
    printf("O valor %d multiplicado por 3 é igual a: %d\n", n, n * 3);
}

// Função que eleva um inteiro ao quadrado
void elevarAoQuadrado(int n)
{
    printf("O valor %d elevado ao quadrado é igual a: %d\n", n, n * n);
}

// Função que eleva um inteiro ao cubo
void elevarAoCubo(int n)
{
    printf("O valor %d elevado ao cubo é igual a: %d\n", n, n * n * n);
}

// Função que recebe um ponteiro para uma função e um inteiro
void aplicarFuncao(void (*f)(int), int n)
{
    f(n);
}

// Função principal
int main()
{
    aplicarFuncao(imprimir, 10); // Passando a função imprimir como argumento, 10 é o argumento para a função imprimir
    aplicarFuncao(imprimir, 20); // Passando a função imprimir como argumento, 20 é o argumento para a função imprimir
    aplicarFuncao(imprimir, 30); // Passando a função imprimir como argumento, 30 é o argumento para a função imprimir
    aplicarFuncao(imprimir, 40); // Passando a função imprimir como argumento, 40 é o argumento para a função imprimir
    aplicarFuncao(imprimir, 50); // Passando a função imprimir como argumento, 50 é o argumento para a função imprimir

    aplicarFuncao(duplicar, 10);         // Passando a função duplicar como argumento, 10 é o argumento para a função duplicar
    aplicarFuncao(triplicar, 10);        // Passando a função triplicar como argumento, 10 é o argumento para a função triplicar
    aplicarFuncao(somar, 10);            // Passando a função somar como argumento, 10 é o argumento para a função somar
    aplicarFuncao(subtrair, 10);         // Passando a função subtrair como argumento, 10 é o argumento para a função subtrair
    aplicarFuncao(dividir, 10);          // Passando a função dividir como argumento, 10 é o argumento para a função dividir
    aplicarFuncao(multiplicar, 10);      // Passando a função multiplicar como argumento, 10 é o argumento para a função multiplicar
    aplicarFuncao(elevarAoQuadrado, 10); // Passando a função elevarAoQuadrado como argumento, 10 é o argumento para a função elevarAoQuadrado
    aplicarFuncao(elevarAoCubo, 10);     // Passando a função elevarAoCubo como argumento, 10 é o argumento para a função elevarAoCubo

    return 0;
}