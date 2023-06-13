#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void print_error(const char *message, const char *filename, int code);

#endif /* MAIN_H */
