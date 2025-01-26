#include <iostream>

struct Structure {
    char f1;
    long long f2;
    char f3;
};

int main() {
    std::cout << alignof(Structure) << std::endl;
}
