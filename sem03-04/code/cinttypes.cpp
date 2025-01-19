#include <cinttypes>
#include <cstdio>

int main() {
    uint8_t a = 15;

    std::printf("write 8-byte usigned number: ");
    std::scanf("%" SCNu8, &a);
    std::printf("a in dec: %" PRIu8 "\n", a);
    std::printf("a in oct: %" PRIo8 "\n", a);
    std::printf("a in hex: %" PRIx8 "\n", a);
    std::printf("a in hex: %" PRIX8 "\n", a);

    const std::uint32_t b = 0123;
    std::printf("b in dec: %" PRIu32 "\n", b);
    std::printf("b in oct: %" PRIo32 "\n", b);

    const std::uint32_t c = 0x123;
    std::printf("c in dec: %" PRIu32 "\n", c);
    std::printf("c in hex: %" PRIX32 "\n", c);
}
