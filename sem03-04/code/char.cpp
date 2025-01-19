#include <ios>
#include <iostream>
#include <limits>

int main() {

    std::cout << "char: " << std::numeric_limits<char>::digits << std::endl;
    std::cout << "signed char: " << std::numeric_limits<signed char>::digits << std::endl;
    std::cout << "unsigned char: " << std::numeric_limits<unsigned char>::digits << std::endl;

    std::cout << std::boolalpha << "char == unsigned char: "
        << (std::numeric_limits<char>::digits ==
        std::numeric_limits<unsigned char>::digits)
        << std::endl;
}
