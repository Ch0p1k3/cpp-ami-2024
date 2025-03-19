#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    for (int e : v) {
        if (e % 2 == 0) {
            std::cout << e * e << std::endl;
        }
    }
}
