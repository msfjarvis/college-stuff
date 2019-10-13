format:
	clang-format -i *.c conio.h

%.out: %.c
	clang -Wall -Werror $< -o $@ -I $(shell pwd)/../common

build:	$(addsuffix .out, $(basename $(wildcard *.c)))

clean:
	rm -f *.out

.DEFAULT_GOAL := build
