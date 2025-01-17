
build:
	gcc -o gauss main.c gauss.c matrix.c -lm
	gcc -o test test.c gauss.c matrix.cgit

execute:
	./gauss ./test

run: build execute