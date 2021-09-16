all: openhttest unorderedhttest

unorderedhttest: unorderedhttest.cpp
	g++ -std=c++11 -o  unorderedhttest unorderedhttest.cpp

openhttest: openhttest.cpp
	g++ -std=c++11 -o  openhttest openhttest.cpp

# List all the executables under 'all:'
clean:
	rm openhttest unorderedhttest