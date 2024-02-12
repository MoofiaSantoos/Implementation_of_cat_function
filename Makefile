CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -pedantic

all: cat

cat: clean
	$(CC) $(CFLAGS) cat.c -o cat

clean: 
	rm -rf cat

rebuild: all

clang:
	clang-format -i *.c *.h