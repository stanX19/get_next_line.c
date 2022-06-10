#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFERSIZE
#  define BUFFERSIZE 5
# endif
char* get_next_line(int fd);
char* get_next_line2(int fd);
char* substr(char* str, int start, int end);
void *ft_memset(void*b, int c, size_t len);
int find(char*str, int start, int end, char target);
void * ft_memcpy(void *restrict dst, const void *restrict src, int n);

#endif