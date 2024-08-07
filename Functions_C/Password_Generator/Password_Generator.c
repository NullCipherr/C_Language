#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <openssl/rand.h>

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void gerarSenha(int comprimento, const char *caracteres, const char *charsPersonalizados) 
{
    int tamanhoCaracteres = strlen(caracteres);

    if (tamanhoCaracteres == 0) 
    {
        printf("Erro: Nenhum tipo de caractere selecionado para a senha.\n");
        return;
    }

    printf("A Senha foi gerada com sucesso!!\n");

    unsigned char *senha = (unsigned char *)malloc(comprimento);
    int tamanhoCaracteresPersonalizados = strlen(charsPersonalizados);

    if (!senha) 
    {
        printf("Erro: Falha na alocação de memória.\n");
        return;
    }

    if (RAND_bytes(senha, comprimento) != 1) 
    {
        printf("Erro: Falha ao gerar números aleatórios seguros.\n");
        free(senha);
        return;
    }

    for (int i = 0; i < comprimento; i++) 
    {
        int indice;
        if (tamanhoCaracteresPersonalizados > 0 && (senha[i] % 2 == 0)) 
        {
            indice = senha[i] % tamanhoCaracteresPersonalizados;
            printf("%c", charsPersonalizados[indice]);
        } 
        else 
        {
            indice = senha[i] % tamanhoCaracteres;
            printf("%c", caracteres[indice]);
        }
    }

    free(senha);
    printf("\n");
}

double calcularForcaSenha(int comprimento, int tamanhoCaracteres, int tamanhoCaracteresPersonalizados) 
{
    // Calcular a entropia da senha
    double entropia = log2(pow(tamanhoCaracteres + tamanhoCaracteresPersonalizados, comprimento));
    return entropia;
}

int main() 
{
    int comprimento ;
    char caracteres[128] = "" ;
    char charsPersonalizados[128] = "" ;
    int opcao ; 

    printf("\n======================================\n");
    printf("Password Generator v.0.0.2\n");
    printf("======================================\n\n");

    printf("Comprimento da senha --> ");
    scanf("%d", &comprimento);

    printf("\n===========================================================\n");
    printf("1. Letras maiúsculas (ABCDEFGHIJKLMNOPQRSTUVWXYZ)\n");
    printf("2. Letras minúsculas (abcdefghijklmnopqrstuvwxyz)\n");
    printf("3. Números (0123456789)\n");
    printf("4. Caracteres especiais (!@#$%^&*()_-+=<>?)\n");
    printf("5. Incluir caracteres personalizados\n");
    printf("===========================================================\n");

    do {
        printf("Opção (0 para concluir): ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                strcat(caracteres, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
                break;
            case 2:
                strcat(caracteres, "abcdefghijklmnopqrstuvwxyz");
                break;
            case 3:
                strcat(caracteres, "0123456789");
                break;
            case 4:
                strcat(caracteres, "!@#$%^&*()_-+=<>?");
                break;
            case 5:
                printf("Digite os caracteres personalizados: ");
                scanf(" %s", charsPersonalizados);
                break;
            case 0:
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    if (strlen(caracteres) == 0 && strlen(charsPersonalizados) == 0) {
        printf("\nErro: Nenhuma opção selecionada para a senha!!\n");
    } else {
        double forcaSenha = calcularForcaSenha(comprimento, strlen(caracteres), strlen(charsPersonalizados));
        printf("\nForça da senha --> %.2f bits\n", forcaSenha);
        gerarSenha(comprimento, caracteres, charsPersonalizados);
    }

    return 0;
}
