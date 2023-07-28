#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <limits.h>

extern char **environ;

void simple_shell_loop(void);
char *read_line(void);
char **div_line(char *line);
void free_tokens(char **tokens);
void exeout(char **argv);
char *found_path(char *comm);
void _puts(char *str);
int _putchar(char c);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strdup(const char *str);
int file_exists(const char *filename);
char *create_executable_path(const char *directory, const char *command);
char *find_exe(char *comm, char *path);
int print_format(const char *format, va_list args);
int _printf(const char *format, ...);
int write_format(const char *format, va_list args, int q);
int print_string(va_list args);
int print_int(va_list args);

#endif
