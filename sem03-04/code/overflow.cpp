#include <iostream>
#include <limits>

int main() {
    int32_t res = std::numeric_limits<int32_t>::max();
    res += res;
    std::cout << res << std::endl;
}
