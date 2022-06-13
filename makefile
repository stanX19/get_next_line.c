DATE = $$(date -I)

run:
	gcc -Wall -Wextra -Werror -fsanitize=address -g3 *.c && ./a.out

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
	git commit -m $(DATE)