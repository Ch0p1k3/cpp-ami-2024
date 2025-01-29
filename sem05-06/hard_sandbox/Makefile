CC=clang++
CXXFLAGS=-O3 --std=c++20
EXTRA_CXXFLAGS=

echo:
	echo "1"

hello_world: echo
	$(CC) $(CXXFLAGS) $(EXTRA_CXXFLAGS) bin/main.cpp libs/hello/double_print_hello.cpp libs/hello/print_hello.cpp -I . -o hard_sandbox
