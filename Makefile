all:
	gcc -Wall -Wextra -Werror -c src/*.c
	gcc *.o -o bsq
	rm *.o
fast:
	gcc -c src/*.c
	gcc *.o -o bsq
	./bsq
clean:
	rm *.o
fclean:
	rm *.o
	rm bsq
