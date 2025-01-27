#include <iostream>

int main(int argc, const char* argv[], const char* env[]) {
    for (size_t i = 0; i < 10; ++i) {
        std::cout << env[i] << std::endl;
    }
}
