#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main() {
	int fd;
	//int fd2;
	char* line;
	//int start;
	//line = get_next_line(fd);
	//line = malloc(1024 * sizeof(char));

	//start = 0;
	fd = open("test.txt", O_RDONLY);
	do {
		
		line = get_next_line2(fd);
		
		if (line) {
			printf("%s", line);
			free(line);
		}
	} while (line);
	close(fd);
}