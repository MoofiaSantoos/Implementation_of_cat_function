CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -pedantic

all:
	$(CC) $(CFLAGS) cat.c -o mycat

clean: 
	rm -rf mycat

rebuild: all

clang:
	clang-format -i *.c *.h