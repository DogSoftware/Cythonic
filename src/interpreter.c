#include "interpreter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>

#define MAX_COMMAND_LENGTH 1024

void trim_whitespace(char* str) {
    char* end;

    while (isspace((unsigned char)*str)) str++;

    if (*str == 0)
        return;

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    *(end + 1) = '\0';
}

char* extract_command_arg(char* command, const char* cmd_name) {
    char* arg = command + strlen(cmd_name);
    while (isspace((unsigned char)*arg)) arg++;
    return arg;
}

void execute_command(const Program* program) {
    char* command = program->code;
    char trimmed_command[MAX_COMMAND_LENGTH];

    char* line = strtok(command, "\n");

    while (line != NULL) {
        strncpy(trimmed_command, line, sizeof(trimmed_command) - 1);
        trimmed_command[sizeof(trimmed_command) - 1] = '\0';

        trim_whitespace(trimmed_command);

        char* start = trimmed_command;
        if (strstr(start, "print") == start) {
            char* p_start = strstr(start, "print(") + 6;
            char* p_end = strstr(p_start, ")");
            if (p_end) {
                *p_end = '\0';
                printf("%s\n", p_start);
            }
            else {
                fprintf(stderr, "Error: Malformed print command.\n");
            }
        }
        else if (strstr(start, "wait") == start) {
            int seconds = atoi(extract_command_arg(start, "wait"));
            if (seconds > 0) {
                sleep(seconds);
            }
            else {
                fprintf(stderr, "Error: Invalid wait time.\n");
            }
        }
        else if (strstr(start, "version") == start) {
            printf("Cythonic Version: 0.1.0\n");
        }
        else if (strstr(start, "create_file") == start) {
            char* filename = extract_command_arg(start, "create_file");
            trim_whitespace(filename);
            FILE* file = fopen(filename, "w");
            if (file) {
                fclose(file);
            }
            else {
                fprintf(stderr, "Error: Could not create file: %s\n", filename);
            }
        }
        else if (strstr(start, "read_file") == start) {
            char* filename = extract_command_arg(start, "read_file");
            trim_whitespace(filename);
            FILE* file = fopen(filename, "r");
            if (file) {
                char buffer[MAX_COMMAND_LENGTH];
                while (fgets(buffer, sizeof(buffer), file)) {
                    printf("%s", buffer);
                }
                fclose(file);
            }
            else {
                fprintf(stderr, "Error: Could not read file: %s\n", filename);
            }
        }
        else if (strstr(start, "append_file") == start) {
            char* filename = strtok(extract_command_arg(start, "append_file"), " ");
            char* content_start = strchr(start, '{') + 1;
            char* content_end = strrchr(start, '}');
            if (filename && content_start && content_end) {
                *content_end = '\0';
                FILE* file = fopen(filename, "a");
                if (file) {
                    fprintf(file, "%s", content_start);
                    fclose(file);
                }
                else {
                    fprintf(stderr, "Error: Could not append to file: %s\n", filename);
                }
            }
            else {
                fprintf(stderr, "Error: Malformed append_file command.\n");
            }
        }
        else if (strstr(start, "delete_file") == start) {
            char* filename = extract_command_arg(start, "delete_file");
            trim_whitespace(filename);
            if (remove(filename) == 0) {
                printf("File %s deleted successfully.\n", filename);
            }
            else {
                fprintf(stderr, "Error: Could not delete file: %s\n", filename);
            }
        }
        else if (strstr(start, "open_url") == start) {
            char* url = extract_command_arg(start, "open_url");
            trim_whitespace(url);
            printf("Opening URL: %s\n", url);
        }
        else if (strstr(start, "current_time") == start) {
            time_t now = time(NULL);
            struct tm* tm_info = localtime(&now);
            char buffer[26];
            strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
            printf("Current time: %s\n", buffer);
        }
        else if (strstr(start, "math_add") == start) {
            int a = atoi(strtok(extract_command_arg(start, "math_add"), " "));
            int b = atoi(strtok(NULL, " "));
            printf("Result: %d\n", a + b);
        }
        else if (strstr(start, "math_subtract") == start) {
            int a = atoi(strtok(extract_command_arg(start, "math_subtract"), " "));
            int b = atoi(strtok(NULL, " "));
            printf("Result: %d\n", a - b);
        }
        else if (strstr(start, "math_multiply") == start) {
            int a = atoi(strtok(extract_command_arg(start, "math_multiply"), " "));
            int b = atoi(strtok(NULL, " "));
            printf("Result: %d\n", a * b);
        }
        else if (strstr(start, "math_divide") == start) {
            int a = atoi(strtok(extract_command_arg(start, "math_divide"), " "));
            int b = atoi(strtok(NULL, " "));
            if (b != 0) {
                printf("Result: %f\n", (double)a / b);
            }
            else {
                fprintf(stderr, "Error: Division by zero.\n");
            }
        }
        else if (strstr(start, "reverse") == start) {
            char* str = extract_command_arg(start, "reverse");
            trim_whitespace(str);
            char* end = str + strlen(str) - 1;
            while (end >= str) {
                printf("%c", *end--);
            }
            printf("\n");
        }
        else if (strstr(start, "length") == start) {
            char* str = extract_command_arg(start, "length");
            trim_whitespace(str);
            printf("Length: %zu\n", strlen(str));
        }
        else if (strstr(start, "to_upper") == start) {
            char* str = extract_command_arg(start, "to_upper");
            trim_whitespace(str);
            while (*str) {
                printf("%c", toupper(*str++));
            }
            printf("\n");
        }
        else if (strstr(start, "to_lower") == start) {
            char* str = extract_command_arg(start, "to_lower");
            trim_whitespace(str);
            while (*str) {
                printf("%c", tolower(*str++));
            }
            printf("\n");
        }
        else if (strstr(start, "sort") == start) {
            char* str = extract_command_arg(start, "sort");
            trim_whitespace(str);
            size_t len = strlen(str);
            for (size_t i = 0; i < len - 1; i++) {
                for (size_t j = 0; j < len - i - 1; j++) {
                    if (str[j] > str[j + 1]) {
                        char temp = str[j];
                        str[j] = str[j + 1];
                        str[j + 1] = temp;
                    }
                }
            }
            printf("Sorted: %s\n", str);
        }
        else if (strstr(start, "repeat") == start) {
            int times = atoi(strtok(extract_command_arg(start, "repeat"), " "));
            char* str = strtok(NULL, " ");
            if (str) {
                for (int i = 0; i < times; i++) {
                    printf("%s\n", str);
                }
            }
            else {
                fprintf(stderr, "Error: String not specified.\n");
            }
        }
        else if (strstr(start, "copy_file") == start) {
            char* source = strtok(extract_command_arg(start, "copy_file"), " ");
            char* dest = strtok(NULL, " ");
            if (source && dest) {
                FILE* src = fopen(source, "r");
                if (src) {
                    FILE* dst = fopen(dest, "w");
                    if (dst) {
                        char buffer[MAX_COMMAND_LENGTH];
                        while (fgets(buffer, sizeof(buffer), src)) {
                            fputs(buffer, dst);
                        }
                        fclose(dst);
                    }
                    else {
                        fprintf(stderr, "Error: Could not open destination file: %s\n", dest);
                    }
                    fclose(src);
                }
                else {
                    fprintf(stderr, "Error: Could not open source file: %s\n", source);
                }
            }
            else {
                fprintf(stderr, "Error: Source or destination filename not specified.\n");
            }
        }
        else if (strstr(start, "hasta la vista baby;") == start) {
            printf("Terminating program. Hasta la vista baby!\n");
            exit(0);
        }
        else {
            fprintf(stderr, "Error: Unknown command.\n");
        }

        line = strtok(NULL, "\n");
    }
}
