#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main() {
	int fd;
	int idx;
	char* line;
	//int start;
	//line = get_next_line(fd);
	//line = malloc(1024 * sizeof(char));

	//start = 0;
	idx = 0;
	fd = open("test.txt", O_RDONLY);
	do {
		idx++;
		line = get_next_line(fd);
		printf("%s", line);
		if (line)
			free(line);
	} while (line && idx < 1000);
	printf("$\n");
	close(fd);
}