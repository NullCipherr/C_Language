#include <stdio.h>
#include <stdlib.h>

// Estrutura de nó para representar um elemento na biblioteca
struct LibraryNode {
    int value;
    struct LibraryNode *next;
};

// Função para inserir um elemento na biblioteca ordenadamente
void insertIntoLibrary(struct LibraryNode **library, int value) {
    struct LibraryNode *newNode = (struct LibraryNode *)malloc(sizeof(struct LibraryNode));
    newNode->value = value;
    newNode->next = NULL;

    if (*library == NULL || value < (*library)->value) {
        newNode->next = *library;
        *library = newNode;
    } else {
        struct LibraryNode *current = *library;
        while (current->next != NULL && current->next->value <= value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Função para ordenar um array usando o Library Sort
void librarySort(int array[], int size) {
    struct LibraryNode *library = NULL;

    for (int i = 0; i < size; i++) {
        insertIntoLibrary(&library, array[i]);
    }

    struct LibraryNode *current = library;

    for (int i = 0; i < size; i++) {
        array[i] = current->value;
        current = current->next;
    }

    // Liberar memória da biblioteca
    while (library != NULL) {
        struct LibraryNode *temp = library;
        library = library->next;
        free(temp);
    }
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *array = (int *)malloc(size * sizeof(int));

    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("V[%d]: ", i + 1);
        scanf("%d", &array[i]);
    }

    librarySort(array, size);

    printf("Sorted Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d   ", array[i]);
    }

    printf("\n\n");

    free(array);

    return 0;
}
