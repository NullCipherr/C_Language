#include <stdio.h>

void siftDown(int arr[], int root, int end) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left <= end && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right <= end && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != root) {
        int temp = arr[root];
        arr[root] = arr[largest];
        arr[largest] = temp;
        siftDown(arr, largest, end);
    }
}

void heapify(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        siftDown(arr, i, size - 1);
    }
}

void smoothSort(int arr[], int size) {
    if (size <= 1) {
        return;
    }

    heapify(arr, size);

    for (int i = size - 1; i >= 1; i--) {
        if (arr[i] < arr[0]) {
            int temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;
            siftDown(arr, 0, i - 1);
        }
    }

    for (int i = 1; i < size - 1; i += 2) {
        if (arr[i] > arr[i + 1]) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    smoothSort(arr, size - 1);
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("V[%d]: ", i + 1);
        scanf("%d", &arr[i]);
    }

    smoothSort(arr, size);

    printf("Sorted Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d   ", arr[i]);
    }

    printf("\n\n");

    return 0;
}
