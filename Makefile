# Makes the matrix multiplication program.
# Mitch Lane
# Project 1
# CPE 419

CC = g++
CFLAGS = -std=c++0x -O3 -o tsp

ifdef DOUBLE
CFLAGS += -D DOUBLE
else
CFLAGS += -D SINGLE
endif

all:
	$(CC) $(CFLAGS) *.cpp -lpthread

clean:
	rm tsp
