#include <cstdint>
#include <iostream>

int main() {
    const uint32_t a = 0b10000001;
    std::cout << "without cast: " << std::bitset<32>(a) << std::endl;
    std::cout << "cast to uint8_t: " << std::bitset<32>(static_cast<uint8_t>(a)) << std::endl;
    std::cout << "cast to int8_t: " << std::bitset<32>(static_cast<int8_t>(a)) << ", number: " << (int)static_cast<int8_t>(a) << std::endl;
    std::cout << "cast to int32_t: " << std::bitset<32>(static_cast<int32_t>(a)) << std::endl;
}
