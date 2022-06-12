run:
	gcc -Wall -Wextra -Werror *.c && ./a.out

test: gnlTester
	cd gnlTester && make && make fclean

gnlTester:
	git clone https://github.com/Tripouille/gnlTester.git

fclean:
	rm -rf gnlTester