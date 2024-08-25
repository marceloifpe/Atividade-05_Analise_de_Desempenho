#include <stdio.h>
#include <stdlib.h>
#include "MemoryTracker.h"

// Variável global para rastreamento do uso total de memória
size_t total_memory_used = 0;

void *my_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr != NULL) {
        total_memory_used += size;
    }
    return ptr;
}

void my_free(void *ptr) {
    free(ptr);
}
