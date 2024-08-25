#include <stdio.h>
#include <stdlib.h>
#include "MemoryTracker.h"

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)my_malloc(n1 * sizeof(int));
    int *R = (int *)my_malloc(n2 * sizeof(int));

    if (L == NULL || R == NULL) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    my_free(L);
    my_free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
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

    mergeSort(arr, 0, count - 1);

    char newFilePath[100];
    snprintf(newFilePath, sizeof(newFilePath), "arq-teste-ordenado_Efic.txt");
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
