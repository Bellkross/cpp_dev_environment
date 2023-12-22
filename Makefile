# Makefile for running the C++ program

run:
	g++ -o main main.cpp && ./main && rm -rf ./main 