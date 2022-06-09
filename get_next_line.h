#ifndef HEADER_H
#define HEADER_H
#include <unistd.h>
#include <stdlib.h>

char* get_next_line(int fd);
char* substr(char* str, int start, int end);
char* read_to_break(int fd, int *start);

#endif