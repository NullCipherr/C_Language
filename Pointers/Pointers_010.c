// Ponteiros e Listas Encadeadas
//
// Listas encadeadas são estruturas de dados que consistem em uma sequência de elementos, onde cada elemento é um nó que contém um valor e um ponteiro para o próximo nó na sequência.
// Em C, listas encadeadas são frequentemente implementadas usando ponteiros.

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura No
struct No
{
    int valor;
    struct No *proximo;
};

// Função para criar um novo nó
void imprimirLista(struct No *cabeca)
{
    struct No *atual = cabeca; // Inicializa o nó atual com a cabeça da lista

    printf("\nImprimindo a lista encadeada...\n");

    // Enquanto não chegarmos ao final da lista
    while (atual != NULL)
    {
        printf("%d -> ", atual->valor); // Imprime o valor do nó atual
        atual = atual->proximo;         // Avança para o próximo nó
    }

    printf("NULL\n"); // Imprime NULL no final da lista
}

// Função para inserir um novo nó no início da lista
void inserirNo(struct No **cabeca, int valor)
{
    struct No *novoNo = (struct No *)malloc(sizeof(struct No)); // Aloca memória para o novo nó
    novoNo->valor = valor;                                      // Atribui o valor ao novo nó
    novoNo->proximo = *cabeca;                                  // O próximo do novo nó aponta para a cabeça da lista
    *cabeca = novoNo;                                           // Atualiza a cabeça da lista para o novo nó
}

// Função para remover o primeiro nó da lista
void removerNo(struct No **cabeca)
{
    // Verifica se a lista não está vazia
    if (*cabeca != NULL)
    {
        struct No *temp = *cabeca;    // Salva a cabeça da lista em um nó temporário
        *cabeca = (*cabeca)->proximo; // Atualiza a cabeça da lista para o próximo nó
        free(temp);                   // Libera a memória alocada para o nó removido
    }
}

void liberarLista(struct No **cabeca)
{
    struct No *atual = *cabeca; // Inicializa o nó atual com a cabeça da lista
    struct No *proximo = NULL;  // Inicializa o próximo nó como NULL

    printf("\nLiberando a lista encadeada...\n");

    // Enquanto não chegarmos ao final da lista
    while (atual != NULL)
    {
        proximo = atual->proximo; // Salva o próximo nó
        free(atual);              // Libera a memória alocada para o nó atual
        atual = proximo;          // Avança para o próximo nó
    }

    *cabeca = NULL; // Atualiza a cabeça da lista para NULL
}

void inserirNoAleatorio(struct No **cabeca)
{
    printf("\nDigite a quantidade de nós a serem inseridos: ");
    int n;
    scanf("%d", &n);

    printf("\nInserindo %d nós aleatórios no início da lista...\n", n);

    for (int i = 0; i < n; i++)
    {

        int valor = rand() % 100;                                   // Gera um valor aleatório entre 0 e 99
        struct No *novoNo = (struct No *)malloc(sizeof(struct No)); // Aloca memória para o novo nó
        novoNo->valor = valor;                                      // Atribui o valor ao novo nó
        novoNo->proximo = NULL;                                     // O próximo do novo nó aponta para NULL

        // Verifica se a lista está vazia
        if (*cabeca == NULL)
        {
            *cabeca = novoNo; // Se a lista estiver vazia, o novo nó se torna a cabeça da lista
        }
        else
        {
            struct No *atual = *cabeca; // Inicializa o nó atual com a cabeça da lista

            // Enquanto não chegarmos ao final da lista
            while (atual->proximo != NULL)
            {
                atual = atual->proximo; // Avança para o próximo nó
            }

            atual->proximo = novoNo; // O próximo do último nó aponta para o novo nó
        }
    }
}

void ordenarLista(struct No **cabeca)
{
    struct No *atual = *cabeca; // Inicializa o nó atual com a cabeça da lista
    struct No *proximo = NULL;  // Inicializa o próximo nó como NULL

    printf("\nOrdenando a lista encadeada...\n");

    // Enquanto não chegarmos ao final da lista
    while (atual != NULL)
    {
        proximo = atual->proximo; // Salva o próximo nó

        // Enquanto não chegarmos ao final da lista
        while (proximo != NULL)
        {
            // Se o valor do nó atual for maior que o valor do próximo nó
            if (atual->valor > proximo->valor)
            {
                // Troca os valores dos nós
                int temp = atual->valor;
                atual->valor = proximo->valor;
                proximo->valor = temp;
            }

            proximo = proximo->proximo; // Avança para o próximo nó
        }

        atual = atual->proximo; // Avança para o próximo nó
    }
}

void menuOpcao(struct No **cabeca)
{
    int opcao, valor;
    printf("\n      +++ Lista Encadeada +++ \n\n");
    printf("<1> Inserir um nó no inicio da lista\n");
    printf("<2> Ordenar\n");

    printf("<3> Remover o primeiro nó da lista\n");
    printf("<4> Imprimir a lista\n");
    printf("<5> Liberar a lista\n");
    printf("<6> Sair\n");

    printf("\nSelecione -> ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        printf("<1>Manual <2>Aleatório: \n");
        scanf("%d", &valor);
        if (valor == 1)
        {
            printf("Digite o valor do nó: ");
            scanf("%d", &valor);
            inserirNo(cabeca, valor);
        }
        else
        {
            inserirNoAleatorio(cabeca);
        }
        break;
    case 2:
        ordenarLista(cabeca);
        break;
    case 3:
        removerNo(cabeca);
        break;
    case 4:
        imprimirLista(*cabeca);
        break;
    case 5:
        liberarLista(cabeca);
        break;
    case 6:
        exit(0);
    default:
        printf("Opção inválida. Tente novamente.\n");
    }
}

int main()
{
    struct No *cabeca = NULL; // Inicializa a cabeça da lista como NULL

    while (1)
    {
        menuOpcao(&cabeca);
    }

    return 0;
}