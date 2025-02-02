#include "stack.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Empty test") {
    Stack s;
    REQUIRE(s.Empty());
}

TEST_CASE("Push and pop test") {
    Stack s;
    s.Push(1);
    REQUIRE(!s.Empty());
    REQUIRE(s.Top() == 1);
    REQUIRE(s.Pop() == 1);
    REQUIRE(s.Empty());
}

TEST_CASE("Copy operator and constructor") {
    Stack s;
    s.Push(1);
    s.Push(2);
    Stack s1(s);
    REQUIRE(s1.Top() == 2);
    REQUIRE(!s1.Empty());
    REQUIRE(s1.Pop() == 2);
    REQUIRE(s1.Top() == 1);
    REQUIRE(!s1.Empty());

    Stack s2;
    s2 = s;
    REQUIRE(s2.Pop() == 2);
    REQUIRE(!s2.Empty());
    REQUIRE(s2.Pop() == 1);
    REQUIRE(s2.Empty());
}
