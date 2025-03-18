#include <algorithm>
#include <cassert>
#include <concepts>
#include <iostream>
#include <random>
#include <vector>
#include <ranges>

namespace {

template <std::integral T = int>
auto CreateRandomRange(T min_value = 0, T max_value = 100) {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(min_value, max_value);

    return std::ranges::views::iota(0)
        | std::ranges::views::transform([&](int) mutable { return dis(gen); });
}

}  //namespace

int main() {
    static constexpr auto kVectorSize = 100;
    std::vector<int> v;
    v.reserve(kVectorSize);
    for (const auto e : CreateRandomRange() | std::ranges::views::take(kVectorSize)) {
        v.push_back(std::move(e));
    }
    std::ranges::sort(v);
    for (const auto e : v) {
        std::cout << e << ' ';
    }
    std::cout << std::endl;
}
