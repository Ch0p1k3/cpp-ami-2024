#include "split.hpp"

#include <string>
#include <vector>

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <catch2/matchers/catch_matchers_range_equals.hpp>
#include <catch2/generators/catch_generators_adapters.hpp>
#include <catch2/generators/catch_generators_random.hpp>

using Catch::Matchers::RangeEquals;

TEST_CASE("Simple") {
    CHECK_THAT(Split("aba caba 1"), RangeEquals(std::vector{"aba", "caba", "1"}));
    CHECK_THAT(Split("aba"), RangeEquals(std::vector{"aba"}));
    CHECK(Split("").empty());
    CHECK_THAT(Split("asdasd", "asdasd"), RangeEquals(std::vector{"", ""}));
    CHECK_THAT(Split("just  a test "), RangeEquals(std::vector{"just", "", "a", "test", ""}));
    CHECK_THAT(Split("hello, world,no split here, , 1, ", ", "),
               RangeEquals(std::vector{"hello", "world,no split here", "", "1", ""}));
    CHECK_THAT(Split("  a  b c  def  g h ", "  "),
               RangeEquals(std::vector{"", "a", "b c", "def", "g h "}));
}
