#include <iostream>

struct Structure {
    int f1;
    long long f2;
    char f3;
};

int main() {
    std::cout << "sizeof=" << sizeof(Structure)
              << ' ' << "alignof=" << alignof(Structure)
              << std::endl;
}
