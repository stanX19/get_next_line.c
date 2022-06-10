#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
char* substr(char* str, int start, int end)
{
	char* ret;
	int idx;

	idx = 0;
	ret = malloc((sizeof(char) * (end - start + 1)));
	while (start < end)
		ret[idx++] = str[start++];
	ret[idx] = 0;
	return ret;
}

char* read_to_break(int fd, int* ended)
{
	int idx;
	char txt[320000];
	memset(txt, 0, 320000);
	idx = -1;
	do{
		read(fd, txt + (++idx), 1);
	}
	while (txt[idx] && txt[idx] != '\n');
	
	if (!txt[idx])
		*ended = 1;
	return substr(txt, 0, ++idx);
}