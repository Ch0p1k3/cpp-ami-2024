#include <catch2/catch_test_macros.hpp>

#include "smart_ptrs.hpp"

#include <string>

TEST_CASE("Empty shared") {
    SharedPtr a;
    SharedPtr b;
    b = a;
    // auto c = a;
    // b = std::move(c);
    REQUIRE(a.Get() == nullptr);
    REQUIRE(b.Get() == nullptr);
}

TEST_CASE("Reset shared") {
    auto* ptr1 = new std::string{"aba"};
    auto* ptr2 = new std::string{"caba"};
    SharedPtr a{ptr1};
    SharedPtr b{ptr2};
    REQUIRE(a.Get() == ptr1);
    REQUIRE(*b == *ptr2);
    a.Reset(nullptr);
    b = a;
}

TEST_CASE("Copy/move shared") {
    SharedPtr a{new std::string{"aba"}};
    std::string* ptr;
    {
        auto b = a;
        auto c = a;
        ptr = c.Get();
    }
    REQUIRE(ptr == a.Get());
    REQUIRE(*ptr == "aba");

    SharedPtr b{new std::string{"caba"}};
    {
        auto c = b;
        auto d = b;
        d = std::move(a);
        REQUIRE(*c == "caba");
        REQUIRE(*d == "aba");
        b.Reset(new std::string{"test"});
        REQUIRE(*c == "caba");
    }
    REQUIRE(*b == "test");

    SharedPtr end;
    {
        SharedPtr d{new std::string{"delete"}};
        d = b;
        auto c = std::move(b);
        REQUIRE(*d == "test");
        REQUIRE(*c == "test");
        const auto& r = d;
        d = r;
        c = end;
        d.Reset(new std::string{"delete"});
        end = d;
    }

    REQUIRE(*end == "delete");
}

TEST_CASE("Empty weak") {
    WeakPtr a;
    WeakPtr b;
    a = b;
    auto c = a;
    b = std::move(c);

    auto shared = b.Lock();
    REQUIRE(shared.Get() == nullptr);
}

TEST_CASE("Weak expiration") {
    WeakPtr* a;
    {
        SharedPtr b{new std::string("aba")};
        auto c = b;
        a = new WeakPtr{c};
        auto test = a->Lock();
        REQUIRE(*test == "aba");
        REQUIRE(!a->IsExpired());
    }
    REQUIRE(a->IsExpired());
    delete a;
}

TEST_CASE("Weak extends shared") {
    auto* b = new SharedPtr{new std::string("aba")};
    WeakPtr c{*b};
    auto a = c.Lock();
    delete b;
    REQUIRE(!c.IsExpired());
    REQUIRE(*a == "aba");
}

TEST_CASE("Copy/move weak") {
    SharedPtr a{new std::string("aba")};
    WeakPtr b{a};
    WeakPtr empty;
    auto c = b;
    WeakPtr d{a};
    REQUIRE(!c.IsExpired());
    c = empty;
    REQUIRE(c.IsExpired());

    b = std::move(c);
    auto locked = d.Lock();
    REQUIRE(*locked == "aba");

    WeakPtr start{a};
    {
        auto a2 = a;
        WeakPtr f{a2};
        auto cur_lock = f.Lock();
        REQUIRE(cur_lock.Get() == SharedPtr{start}.Get());
    }
}

TEST_CASE("Shared from weak") {
    auto* x = new SharedPtr{new std::string{"aba"}};
    WeakPtr y{*x};
    delete x;
    REQUIRE(y.IsExpired());
    SharedPtr z{y};
    REQUIRE(z.Get() == nullptr);
}
