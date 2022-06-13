#include "get_next_line.h"
#include <stdio.h>

static int read_to_buf(int fd, char*buf, int *idx, int*end)
{
	int ret;
	int temp;

	if (BUFFER_SIZE < 0)
		return -1;
	*end = *idx;
	temp = find(buf, 0, *end, '\n');
	ret = BUFFER_SIZE;
	while (temp == -1 && ret == BUFFER_SIZE) {
		ret = read(fd, buf + *end, BUFFER_SIZE);
		if (ret == -1)
			return -1;
		temp = find(buf, *end, *end + ret, '\n');
		*end += ret;
	}
	if (temp == -1)
		*idx = *end - 1;
	else
		*idx = temp;
	return 0;
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
	if (read_to_buf(fd, buf, &idx, &end) == -1 || idx == -1)
		return 0;
	end = end - idx - 1;
	txt = substr(buf, 0, idx + 1);
	ft_memcpy(buf, buf + idx + 1, end);
	idx = end;
	return txt;
}