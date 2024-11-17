# Makefile for running programs

run_cpp:
	g++ -o main main.cpp && ./main && rm -rf ./main 