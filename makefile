all: ./run_test

./run_test: ./test/test.cpp
	g++ -o ./run_test -std=c++11 -I./include ./test/test.cpp
