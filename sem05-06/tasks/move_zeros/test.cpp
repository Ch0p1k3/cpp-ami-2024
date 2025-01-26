#include "move_zeros.hpp"

#include <vector>

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <catch2/matchers/catch_matchers_range_equals.hpp>
#include <catch2/generators/catch_generators_adapters.hpp>
#include <catch2/generators/catch_generators_random.hpp>

using Catch::Matchers::RangeEquals;

TEST_CASE("Simple") {
    for (auto& [arr, expected] : std::vector<std::pair<std::vector<int>, std::vector<int>>>{
        {std::vector<int>{0, 1}, std::vector<int>{1}},
        {std::vector<int>{0, 0, 0, 0, 0, 0, 0, 0}, std::vector<int>{}},
        {std::vector<int>{1, 0, 1, 0, 1, 0, 1}, std::vector<int>{1, 1, 1, 1}},
        {std::vector<int>{6, 1, 2, 0, 0, 0, 1, 7, 2, 6, 5, 3, 3, 0, 0, 1, 8, 2, 7, 3, 0, 1, 8, 5, 8, 4, 9}, std::vector<int>{6, 1, 2, 1, 7, 2, 6, 5, 3, 3, 1, 8, 2, 7, 3, 1, 8, 5, 8, 4, 9}},
        {std::vector<int>{1, 2, 3, 4, 5, 6, 7}, std::vector<int>{1, 2, 3, 4, 5, 6, 7}},
    }) {
        MoveZeros(arr);
        CHECK_THAT(arr, RangeEquals(expected));
    }
}
