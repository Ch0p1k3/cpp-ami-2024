#include <iostream>

enum class Colors : uint64_t {
    RED = 0,
    GREEN = 2,
    BLUE = 4,
    DIRTY = 1 << 10,
};

int main() {
    std::cout << static_cast<int>(static_cast<char>(Colors::DIRTY)) << std::endl;
}
