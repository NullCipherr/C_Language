// Ponteiros e Estruturas
//
// Ponteiros são frequentemnete utilizados em conjunto com estruturas. Isso permite que se acesse os membros de uma estrutura de forma mais eficiente.
// Além disso, ponteiros podem ser utilizados para passar estruturas como parâmetros para funções.

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura Pessoa
struct Pessoa
{
    char nome[50];
    int idade;
    float altura;
    float peso;
};

// Função para preencher os dados da pessoa
void preencherPessoa(struct Pessoa *p)
{
    printf("Digite o nome: ");
    scanf("%s", p->nome);
    printf("Digite a idade: ");
    scanf("%d", &p->idade);
    printf("Digite a altura: ");
    scanf("%f", &p->altura);
    printf("Digite o peso: ");
    scanf("%f", &p->peso);
}

// Função para imprimir os dados da pessoa
void imprimirPessoa(struct Pessoa *p)
{
    printf("Nome: %s\n", p->nome);
    printf("Idade: %d\n", p->idade);
    printf("Altura: %.2f\n", p->altura);
    printf("Peso: %.2f\n", p->peso);
}

// Função para calcular o IMC da pessoa
void calcularIMC(struct Pessoa *p)
{
    float imc = p->peso / (p->altura * p->altura);
    printf("IMC: %.2f\n", imc);
}

// Função para liberar a memória alocada para a estrutura Pessoa
void liberarPessoa(struct Pessoa *p)
{
    free(p);
}

int main()
{
    struct Pessoa *p = (struct Pessoa *)malloc(sizeof(struct Pessoa)); // Aloca memória para a estrutura Pessoa, e atribui o endereço de memória a p

    // Preenche a estrutura Pessoa
    preencherPessoa(p);
    imprimirPessoa(p);

    // Calcula o IMC da pessoa
    calcularIMC(p);

    // Libera a memória alocada para a estrutura Pessoa
    liberarPessoa(p);

    return 0;
}