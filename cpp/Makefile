format:
	clang-format -i *.cpp

%.out: %.cpp
	clang++ -Wall -Werror $< -o $@ -I $(shell pwd)/../common

build:	$(addsuffix .out, $(basename $(wildcard *.cpp)))

clean:
	rm -f *.out

.DEFAULT_GOAL := build
