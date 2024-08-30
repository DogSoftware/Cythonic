#include <stdio.h>
#include <stdlib.h>
#include "interpreter.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <program_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* code = (char*)malloc(file_size + 1);
    if (!code) {
        perror("Memory allocation failed");
        fclose(file);
        return EXIT_FAILURE;
    }

    fread(code, 1, file_size, file);
    code[file_size] = '\0';
    fclose(file);

    Program program = { code };
    execute_command(&program);  // Pass the Program struct to execute_command

    free(code);
    return EXIT_SUCCESS;
}
