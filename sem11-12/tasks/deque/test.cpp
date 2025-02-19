#include "deque.hpp"

#include <string>
#include <vector>
#include <random>
#include <deque>
#include <ranges>
#include <cstddef>

#include <catch2/catch_test_macros.hpp>

void Check(const Deque& actual, const std::vector<int>& expected) {
    REQUIRE(actual.Size() == expected.size());
    for (auto i : std::views::iota(size_t{0}, expected.size())) {
        if (actual[i] != expected[i]) {
            FAIL(actual[i] << " != " << expected[i]);
        }
    }
}

void CheckEq(const Deque& a, const Deque& b) {
    REQUIRE(a.Size() == b.Size());
    for (auto i : std::views::iota(size_t{0}, a.Size())) {
        if (a[i] != b[i]) {
            FAIL(a[i] << " != " << b[i]);
        }
    }
}

TEST_CASE("Deque has constructors") {
    {
        Deque a;
        REQUIRE(a.Size() == 0);
    }
    {
        Deque a = {1, 2, 3, 4};
        Check(a, {1, 2, 3, 4});
    }
    {
        Deque a(5);
        Check(a, std::vector<int>(5));
    }
}

TEST_CASE("Basic methods") {
    Deque a = {1, 3, 5};
    Check(a, {1, 3, 5});

    a.PopBack();
    Check(a, {1, 3});
    a.PopFront();
    Check(a, {3});
    a.PushFront(5);
    Check(a, {5, 3});
    a.PushBack(1);
    Check(a, {5, 3, 1});

    a.Clear();
    Check(a, {});

    a.PushBack(3);
    Deque b{2, 4};
    a.Swap(b);
    Check(a, {2, 4});
    Check(b, {3});
}

TEST_CASE("Modifications with []") {
    Deque a = {9, 1, 1};
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    Check(a, {1, 2, 3});
}

TEST_CASE("Memory layout") {
    Deque a(129);
    for (auto i : std::views::iota(0, 127)) {
        REQUIRE(&a[i] + 1 == &a[i + 1]);
    }
}

TEST_CASE("Reallocations") {
    constexpr auto kRange = std::views::iota(0, 1'000'000);

    std::mt19937 gen{9'354};
    std::bernoulli_distribution dist;
    Deque a;
    std::deque<int*> addr;

    for (auto i : kRange) {
        if (dist(gen)) {
            a.PushBack(i);
            addr.push_back(&a[a.Size() - 1]);
        } else {
            a.PushFront(i);
            addr.push_front(&a[0]);
        }
    }

    for (auto i : kRange) {
        REQUIRE(&a[i] == addr[i]);
    }
}

TEST_CASE("Copy correctness") {
    Deque a;
    auto b = a;
    b.PushBack(1);
    Check(a, {});
    Check(b, {1});

    const auto& r = b;
    b = r;
    Check(b, {1});
    a = b;
    Check(a, {1});
    a.PushFront(3);
    a.PushFront(-3);
    a.PushBack(4);

    b = std::move(a);
    Check(b, {-3, 3, 1, 4});

    auto c = std::move(b);
    Check(c, {-3, 3, 1, 4});

    Deque d = {3, 4, 5};
    auto e = d;
    Check(e, {3, 4, 5});
    d.Swap(c);
    Check(e, {3, 4, 5});
    Check(d, {-3, 3, 1, 4});
    Check(c, {3, 4, 5});
}
