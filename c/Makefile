format:
	clang-format -i *.c conio.h

%.out: %.c
	clang -Wall -Werror $< -o $@

build:	$(addsuffix .out, $(basename $(wildcard *.c)))

.DEFAULT_GOAL := build
