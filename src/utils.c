#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void print_error(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
}

void* safe_malloc(size_t size) {
    void* ptr = malloc(size);
    if (!ptr) {
        print_error("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    return ptr;
}
