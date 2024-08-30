#include "lexer.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1024

Token* create_token(TokenType type, const char* value) {
    Token* token = (Token*)malloc(sizeof(Token));
    if (token == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    token->type = type;
    token->value = duplicate_string(value); // Use duplicate_string
    return token;
}

void free_token(Token* token) {
    if (token) {
        free(token->value);
        free(token);
    }
}

Token** lexer(const char* source_code) {
    Token** tokens = (Token**)malloc(sizeof(Token*) * MAX_TOKENS);
    if (tokens == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    int token_count = 0;
    const char* ptr = source_code;

    while (*ptr != '\0') {
        if (isspace(*ptr)) {
            ptr++;
        }
        else if (isdigit(*ptr)) {
            const char* start = ptr;
            while (isdigit(*ptr)) ptr++;
            size_t length = ptr - start;
            char* value = (char*)malloc(length + 1);
            if (value == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }
            strncpy(value, start, length);
            value[length] = '\0';
            tokens[token_count++] = create_token(TOKEN_NUMBER, value);
            free(value);
        }
        else if (isalpha(*ptr)) {
            const char* start = ptr;
            while (isalpha(*ptr)) ptr++;
            size_t length = ptr - start;
            char* value = (char*)malloc(length + 1);
            if (value == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }
            strncpy(value, start, length);
            value[length] = '\0';
            tokens[token_count++] = create_token(TOKEN_IDENTIFIER, value);
            free(value);
        }
        else if (*ptr == '"') {
            ptr++;
            const char* start = ptr;
            while (*ptr != '"') ptr++;
            size_t length = ptr - start;
            char* value = (char*)malloc(length + 1);
            if (value == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }
            strncpy(value, start, length);
            value[length] = '\0';
            tokens[token_count++] = create_token(TOKEN_STRING, value);
            free(value);
            ptr++;
        }
        else if (*ptr == ':') {
            tokens[token_count++] = create_token(TOKEN_COLON, ":");
            ptr++;
        }
        else {
            printf("Unexpected character: %c\n", *ptr);
            exit(1);
        }
    }
    tokens[token_count] = NULL;
    return tokens;
}
