#include "libs/hello/double_print_hello.h"
#include "libs/hello/print_hello.hpp"
#include "libs/multiplication/multiplication.hpp"

#include <cstdint>
#include <iostream>

int64_t Multiplication(int32_t l, int32_t r) {
    return static_cast<int64_t>(l) * r;
}

int main() {
    PrintHello();
    DoublePrintHello();
    std::cout << Multiplication(1, 2) << std::endl;
}
