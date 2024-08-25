#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MemoryTracker.h"

void readAndSortFile(const char *filePath);

int main() {
    const char *filePath = "arq.txt";

    // Medir o uso de memória antes da execução
    size_t mem_before = total_memory_used;
    printf("Memória alocada antes da execução: %zu KB\n", mem_before);

    clock_t start_time = clock();

    // Ordenar e salvar a lista ordenada
    readAndSortFile(filePath);

    clock_t end_time = clock();
    double elapsed_time_ms = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;

    // Medir o uso de memória após a execução
    size_t mem_after = total_memory_used;
    size_t mem_used = mem_after - mem_before;

    // Exibir informações
    printf("Arquivo ordenado salvo como: arq-teste-ordenado.txt\n");
    printf("Tempo de execução: %.2f ms\n", elapsed_time_ms);
    printf("RAM utilizada: %.2f KB\n", (double)mem_used);

    FILE *result_file = fopen("Resultados/resultado-bubble-c.txt", "a");
    if (result_file == NULL) {
        perror("Erro ao abrir o arquivo de resultados");
        exit(EXIT_FAILURE);
    }
    fprintf(result_file, "Tempo de execução: %.2f ms, RAM utilizada: %.2f KB\n", elapsed_time_ms, (double)mem_used);
    fclose(result_file);

    return 0;
}
