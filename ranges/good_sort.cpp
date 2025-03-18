#include <algorithm>
#include <cassert>
#include <concepts>
#include <iostream>
#include <random>
#include <vector>
#include <ranges>

namespace {

template <std::integral T = int>
std::vector<T> CreateRandomVector(int size = 100, T min_value = 0, T max_value = 100) {
    assert(size > 0);
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(min_value, max_value);

    std::vector<T> result;
    result.reserve(size);
    for (const auto _ : std::ranges::views::iota(0, size)) {
        result.push_back(dis(gen));
    }
    return result;
}

}  //namespace

int main() {
    auto v = CreateRandomVector();
    std::ranges::sort(v);
    for (const auto e : v) {
        std::cout << e << ' ';
    }
    std::cout << std::endl;
}
