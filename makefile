time=$$(date +'%Y-%m-%d %H:%M:%S')
MANDATORY = get_next_line.c get_next_line_utils.c
BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c
FLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

run:
	gcc $(FLAGS) $(BONUS) main.c
	@./a.out

test: gnlTester
	cd gnlTester && make && make fclean

gnlTester:
	git clone https://github.com/Tripouille/gnlTester.git

clean:
	rm -rf ./a.out
fclean: clean
	rm -rf gnlTester
push: fclean
	git add .
	git commit -m "$(time)"
	git push