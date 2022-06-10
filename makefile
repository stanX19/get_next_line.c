run:
	gcc -Wall -Wextra -Werror -fsanitize=address -g3 *.c && ./a.out