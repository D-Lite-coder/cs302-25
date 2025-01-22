CXX=		g++
CXXFLAGS=	-g -Wall -std=gnu++11
SHELL=		bash

all:		lib_info

lib_info:	lib_info.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f lib_info

test:		test-output test-memory

test-output:	lib_info
	@echo Testing output...
	@diff --suppress-common-lines -y <(./lib_info < Music.txt ) output

test-memory:	solution
	@echo Testing memory...
	@[ `valgrind --leak-check=full ./lib_info < input 2>&1 | grep ERROR | awk '{print $$4}'` = 0 ]

