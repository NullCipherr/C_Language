#include <stdio.h>

void cycleSort(int array[], int size) {
    for (int cycleStart = 0; cycleStart < size - 1; cycleStart++) {
        int item = array[cycleStart];
        int position = cycleStart;

        for (int i = cycleStart + 1; i < size; i++) {
            if (array[i] < item) {
                position++;
            }
        }

        if (position == cycleStart) {
            continue; // O elemento já está no lugar certo
        }

        while (item == array[position]) {
            position++; // Evitar ciclos infinitos
        }

        int temp = array[position];
        array[position] = item;
        item = temp;

        while (position != cycleStart) {
            position = cycleStart;

            for (int i = cycleStart + 1; i < size; i++) {
                if (array[i] < item) {
                    position++;
                }
            }

            while (item == array[position]) {
                position++; // Evitar ciclos infinitos
            }

            temp = array[position];
            array[position] = item;
            item = temp;
        }
    }
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size];

    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("V[%d]: ", i + 1);
        scanf("%d", &array[i]);
    }

    cycleSort(array, size);

    printf("Sorted Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d   ", array[i]);
    }

    printf("\n\n");

    return 0;
}
