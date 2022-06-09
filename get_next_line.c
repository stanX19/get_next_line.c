#include "get_next_line.h"

char* get_next_line(int fd)
{
	static int prev_fd;
	static int start;
	int end;
	char* txt;

	if (prev_fd != fd)
	{
		prev_fd = fd;
		start = 0;
	}
	txt = read_to_break(fd, &start);
	if (!txt[0])
		return 0;
	end = start + 1;
	while (txt[end] && txt[end] != '\n')
		end++;
	txt = substr(txt, start, ++end);
	start = end;
	return txt;
}