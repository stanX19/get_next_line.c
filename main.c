#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main() {
	int fd = open("test.txt", O_RDONLY);
	char* line;
	int start;
	//line = get_next_line(fd);
	//line = malloc(1024 * sizeof(char));

	start = 0;
	do {
		line = read_to_break(fd, &start);
		printf("%s\n", line);
		free(line);
	} while (start != -1);

	close(fd);
	//free(line);
}