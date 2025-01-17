
build:
	gcc -o gauss main.c gauss.c matrix.c -lm

execute:
	./gauss

run: build execute