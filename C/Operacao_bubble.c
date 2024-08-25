#include <stdio.h>
#include <stdlib.h>
#include "MemoryTracker.h"

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void readAndSortFile(const char *filePath) {
    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    int *arr = (int *)my_malloc(3000 * sizeof(int));
    if (arr == NULL) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }

    int count = 0;
    while (fscanf(file, "%d", &arr[count]) != EOF) {
        count++;
        if (count >= 3000) {
            fprintf(stderr, "Número máximo de elementos alcançado.\n");
            break;
        }
    }
    fclose(file);

    bubbleSort(arr, count);

    char newFilePath[100];
    snprintf(newFilePath, sizeof(newFilePath), "arq-teste-ordenado.txt");
    file = fopen(newFilePath, "w");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d\n", arr[i]);
    }
    fclose(file);

    my_free(arr);
}
