#include <iostream>
#include <limits>

int main() {
    int32_t res = std::numeric_limits<int32_t>::max();
    res += 1;
    std::cout << res << std::endl;
}
