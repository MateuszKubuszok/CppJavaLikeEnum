all: ./run_test

./run_test: ./test/test.cpp ./test/test.hpp ./include/enum.hpp
	g++ -o ./run_test -std=c++11 -g -I./include -I./test ./test/test.cpp
