all: ./run_test

./run_test: ./test/test.cpp ./include/enum.hpp
	g++ -o ./run_test -std=c++11 -g -I./include ./test/test.cpp
