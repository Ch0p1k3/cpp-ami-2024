CC=clang++
CXXFLAGS=-O3 --std=c++17
EXTRA_CXXFLAGS=

all: alignof struct ptr intmain ptrub

alignof:
	$(CC) $(CXXFLAGS) $(EXTRA_CXXFLAGS) alignof.cpp -o alignof && ./alignof && rm -rf alignof

struct:
	$(CC) $(CXXFLAGS) $(EXTRA_CXXFLAGS) struct.cpp -o struct && ./struct && rm -rf struct

ptr:
	$(CC) $(CXXFLAGS) $(EXTRA_CXXFLAGS) ptr.cpp -o ptr && ./ptr && rm -rf ptr

intmain:
	$(CC) $(CXXFLAGS) $(EXTRA_CXXFLAGS) intmain.cpp -o intmain

ptrub:
	$(CC) $(CXXFLAGS) ptrub.cpp -o ptrub && ./ptrub && rm -rf ptrub
