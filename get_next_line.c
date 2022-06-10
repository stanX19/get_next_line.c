#include "get_next_line.h"
#include <stdio.h>

static int read_to_buf(int fd, char*buf, int *idx, int*end)
{
	int ret;
	int temp;

	*end = *idx;
	do {
		ret = read(fd, buf + *end, BUFFER_SIZE);
		*end += BUFFER_SIZE;
		temp = find(buf, *end - BUFFER_SIZE, *end, '\n');
	} while (temp == -1 && ret == BUFFER_SIZE);
	if (ret != BUFFER_SIZE && ret > -1){
		*end += ret - BUFFER_SIZE;
		*idx += ret - 1;
	}
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
	read_to_buf(fd, buf, &idx, &end);
	if (idx == -1)
		return 0;
	end = end - idx - 1;
	txt = substr(buf, 0, idx + 1);
	ft_memcpy(buf, buf + idx + 1, end);
	
	idx = end;
	
	return txt;
}