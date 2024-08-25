#ifndef MEMORY_TRACKER_H
#define MEMORY_TRACKER_H

#include <stddef.h>

extern size_t total_memory_used;

void *my_malloc(size_t size);
void my_free(void *ptr);

#endif // MEMORY_TRACKER_H
