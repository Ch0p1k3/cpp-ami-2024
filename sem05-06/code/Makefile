CC=clang++
CXXFLAGS=-O3 --std=c++20 -Wall -Werror
EXTRA_CXXFLAGS=

all: alignof struct ptr

alignof:
	$(CC) $(CXXFLAGS) $(EXTRA_CXXFLAGS) alignof.cpp -o alignof && ./alignof && rm -rf alignof

struct:
	$(CC) $(CXXFLAGS) $(EXTRA_CXXFLAGS) struct.cpp -o struct && ./struct && rm -rf struct

ptr:
	$(CC) $(CXXFLAGS) $(EXTRA_CXXFLAGS) ptr.cpp -o ptr && ./ptr && rm -rf ptr
