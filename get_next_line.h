#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif
char* get_next_line(int fd);
char* substr(char* str, int start, int end);
void *ft_memset(void*b, int c, size_t len);
int find(char*str, int start, int end, char target);
void * ft_memcpy(char *dst, const char *src, int n);

#endif