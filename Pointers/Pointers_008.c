// Ponteiros e Alocação Dinâmica de Memória
//
//

#include <stdio.h>
#include <stdlib.h>

// Função para preencher um vetor de inteiros com números aleatórios
void preencherVetorAleatorio(int *arr, int n)
{
    printf("\nPreenchendo o vetor com números aleatórios...\n");
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
}

// Função para preencher um vetor de inteiros manualmente
void preencherVetorManual(int *arr, int n)
{
    printf("\nPreenchendo o vetor manualmente...\n");
    for (int i = 0; i < n; i++)
    {
        printf("Digite o valor do elemento %d: ", i);
        scanf("%d", &arr[i]);
    }
}

// Função para imprimir um vetor de inteiros
void imprimirVetor(int *arr, int n)
{
    printf("\nImprimindo o vetor...\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void menuOpcao(int *arr, int n)
{
    int opcao;
    printf("\nSelecione uma opção:\n");
    printf("1 - Preencher o vetor com números aleatórios\n");
    printf("2 - Preencher o vetor manualmente\n");
    printf("3 - Imprimir o vetor\n");
    printf("4 - Sair\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        preencherVetorAleatorio(arr, n);
        break;
    case 2:
        preencherVetorManual(arr, n);
        break;
    case 3:
        imprimirVetor(arr, n);
        break;
    case 4:
        printf("Saindo...\n");
        break;
    default:
        printf("Opção inválida\n");
    }
}

// Função principal
int main()
{
    int n;
    printf("Digite o número de elementos do vetor: ");
    scanf("%d", &n);

    // Alocar memória para um array de inteiros
    int *arr = (int *)malloc(n * sizeof(int));

    // Verificar se a alocação de memória foi bem-sucedida
    if (arr == NULL)
    {
        printf("Erro ao alocar memória\n");
        return 1;
    }

    // Menu é exibido até que o usuário escolha a opção de sair
    int opcao;
    while (opcao != 2)
    {
        menuOpcao(arr, n);
        printf("\nDeseja continuar? (<1>Sim, <2>Não) : ");
        scanf("%d", &opcao);
    }

    printf("Liberando memória...\n");
    free(arr); // Liberar a memória alocada para o vetor

    return 0;
}