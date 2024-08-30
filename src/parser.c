#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_command(const char* line, Program* program) {
    // This function would be updated based on how you handle command parsing
    // For simplicity, we assume the program code is directly executed
    strcpy(program->code, line);
}
