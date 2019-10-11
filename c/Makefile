format:
	clang-format -i binary_search.c  circular_queue.c  de_queue.c  linear_queue.c  linear_search.c conio.h

%.out: %.c
	clang $< -o $@

build:	$(addsuffix .out, $(basename $(wildcard *.c)))

.DEFAULT_GOAL := build
