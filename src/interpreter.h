#ifndef INTERPRETER_H
#define INTERPRETER_H

typedef struct {
    char* code;
} Program;

void execute_command(const Program* program);

#endif // INTERPRETER_H
