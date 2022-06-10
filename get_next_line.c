#include "get_next_line.h"
#include <stdio.h>

static int read_to_buf(int fd, char*buf, int *idx, int*end)
{
	int ret;
	int temp;

	*end = *idx;
	do {
		ret = read(fd, buf + *end, BUFFERSIZE);
		*end += BUFFERSIZE;
		temp = find(buf, *end - BUFFERSIZE, *end, '\n');
	} while (temp == -1 && ret == BUFFERSIZE);
	if (ret != BUFFERSIZE)
		*idx += ret - 1;
	else
		*idx = temp;
	return ret;
}

char* get_next_line(int fd)
{
	static int prev_fd;
	static int idx;
	static char buf[320000];
	int end;
	char* txt;

	if (prev_fd != fd)
	{
		ft_memset(buf, 0, sizeof(char) * 320000);
		prev_fd = fd;
		idx = 0;
	}
	if (idx == -1)
		return 0;
	//printf("$%s$ idx = %i\n", buf, idx);
	if (read_to_buf(fd, buf, &idx, &end) == 0)
		end = -1;
	else
		end = end - idx - 1;
	//printf("$%s$ idx = %i, end = %i\n", buf, idx, end);
	txt = substr(buf, 0, idx + 1);
	
	ft_memcpy(buf, buf + idx + 1, end);
	idx = end;
	return txt;
}