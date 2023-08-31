CC = g++
OUTPUT = main

all: main

main: solve.cpp
	$(CC) -o $(OUTPUT) solve.cpp
