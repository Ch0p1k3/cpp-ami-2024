#include <iostream>

int* GetPtr(int a) {
    // return &a;
    return nullptr;
}

int* GetPtr2(int& a) {
    return &a;
}

int main() {
    // const auto* ptr = GetPtr(5);
    {
        int a = 3;
        std::cout << a << std::endl;
    }
    int a = 2;
    const auto* ptr2 = GetPtr2(a);
    std::cout << *ptr2 << std::endl;
}
