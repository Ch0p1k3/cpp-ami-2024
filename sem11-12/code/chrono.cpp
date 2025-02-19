#include <chrono>
#include <iostream>
#include <ratio>

using namespace std::literals::chrono_literals;

int main() {
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(1s).count() << std::endl;
}
