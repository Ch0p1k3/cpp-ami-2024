#include <iostream>

namespace foo {

class Foo;

struct Boo {
    Foo* foo;
};

class Foo {
public:
    explicit Foo(int boo, int foo, int moo = 3)
        : boo_(boo)
        , foo_(foo)
        , moo_(moo += 3) {}

    explicit Foo(int boo) : Foo(boo, 2, 3) {}

    int GetMoo() const {
        return moo_;
    }

    Boo NewBoo() {
        return Boo{this};
    }

private:
    int boo_ = 1;
    int foo_ = 2;
    int moo_ = 3;
};

} // namespace foo

int main() {
    foo::Foo f = {1, 2, 3};
    foo::Foo s = 2;
    const auto boo = f.NewBoo();
    std::cout << boo.foo->GetMoo() << std::endl;
}
