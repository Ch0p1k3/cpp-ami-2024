#include <iostream>
#include <limits>

int main() {
    const auto a = std::numeric_limits<int32_t>::max();
    if (a < a + 1) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}
