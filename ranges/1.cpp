#include <iostream>
#include <vector>

int main() {
    auto square = [](int n) { return n * n; };
    std::vector<int> v = {1, 2, 3, 4, 5};
    for (int e : v) {
        if (e % 2 == 0) {
            std::cout << square(e) << std::endl;
        }
    }
}
