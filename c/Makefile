format:
	clang-format -i *.c conio.h

%.out: %.c
	clang $< -o $@

build:	$(addsuffix .out, $(basename $(wildcard *.c)))

.DEFAULT_GOAL := build
