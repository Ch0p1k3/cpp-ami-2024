CC=clang++
CXXFLAGS=-O3 --std=c++20
EXTRA_CXXFLAGS=

all: sizeof cinttypes char overflow cast endian sandbox

sizeof:
	$(CC) $(CXXFLAGS) $(EXTRA_CXXFLAGS) sizeof.cpp -o sizeof && ./sizeof && rm -rf sizeof

cinttypes:
	$(CC) $(CXXFLAGS) $(EXTRA_CXXFLAGS) cinttypes.cpp -o cinttypes && ./cinttypes && rm -rf cinttypes

char:
	$(CC) $(CXXFLAGS) $(EXTRA_CXXFLAGS) char.cpp -o char && ./char && rm -rf char

overflow:
	$(CC) $(CXXFLAGS) $(EXTRA_CXXFLAGS) overflow.cpp -o overflow && ./overflow && rm -rf overflow

cast:
	$(CC) $(CXXFLAGS) $(EXTRA_CXXFLAGS) cast.cpp -o cast && ./cast && rm -rf cast

endian:
	$(CC) $(CXXFLAGS) $(EXTRA_CXXFLAGS) endian.cpp -o endian && ./endian && rm -rf endian

sandbox:
	$(CC) $(CXXFLAGS) $(EXTRA_CXXFLAGS) sandbox.cpp -o sandbox && ./sandbox && rm -rf sandbox
