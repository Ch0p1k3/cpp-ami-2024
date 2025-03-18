#include <iostream>
#include <ranges>

int main() {
    namespace rv = std::ranges::views;
    auto square = [](int n) { return n * n; };
    auto is_even = [](int n) { return n % 2 == 0; };
    for (int e : rv::iota(1, 6) | rv::filter(is_even) | rv::transform(square)) {
        std::cout << e << std::endl;
    }
}
