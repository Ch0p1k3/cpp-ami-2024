#include <iostream>
#include <vector>
#include <ranges>

int main() {
    namespace rv = std::ranges::views;
    auto square = [](int n) { return n * n; };
    auto is_even = [](int n) { return n % 2 == 0; };
    std::vector<int> v = {1, 2, 3, 4, 5};
    for (int e : rv::filter(v, is_even)) {
        std::cout << square(e) << std::endl;
    }
}
