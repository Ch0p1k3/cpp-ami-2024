#include <cstdint>
#include <cstring>
#include <iostream>


int main() {
    char str[] = "Hello";
    char* ptr = str;
    std::cout << static_cast<char>(*ptr + 1) << std::endl;
    uintptr_t uptr = (uintptr_t)ptr;
    std::cout << "ptr=" << ptr << std::endl;
    std::cout << "uptr=" << std::hex << uptr << std::endl;
    std::cout << sizeof(str) << std::endl;
    std::cout << static_cast<int>(str[5]) << std::endl;
    std::cout << std::strlen(str) << std::endl;
    std::string std_string;
    std::cout << std_string.size() << std::endl;
}
