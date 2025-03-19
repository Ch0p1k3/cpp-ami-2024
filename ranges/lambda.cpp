#include <functional>
#include <iostream>
#include <vector>
#include <ranges>

class Lambda {
public:
    explicit Lambda(int two)
        : two_(two) {
    }

    bool operator()(int n) {
        return n % two_ == 0;
    }

private:
    int two_;
};

typedef bool(*IsEvenFunction)(int);
using IsEvenFunction2 = bool(*)(int);
using IsEvenFunction3 = std::function<bool(int)>;

int main() {
    namespace rv = std::ranges::views;
    auto kTwo = 2;
    std::function<bool(int)> is_even = [kTwo](int n) { return n % kTwo == 0; };
    IsEvenFunction is_even2 = [](int n) { return n % 2 == 0; };
    IsEvenFunction2 is_even3 = [](int n) { return n % 2 == 0; };
    IsEvenFunction3 is_even4 = [](int n) { return n % 2 == 0; };
    auto is_even5 = Lambda(kTwo);
    std::vector<int> v = {1, 2, 3, 4, 5};
    for (int e : rv::filter(v, is_even2)) {
        std::cout << e * e << std::endl;
    }
    for (int e : rv::filter(v, is_even5)) {
        std::cout << e * e << std::endl;
    }
}
