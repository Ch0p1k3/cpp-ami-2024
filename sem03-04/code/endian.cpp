#include <cstdint>
#include <cstdio>

int main () {
    const uint16_t x = 0x0001;
    printf("%s-endian\n", *((uint8_t *) &x) ? "little" : "big");
}
