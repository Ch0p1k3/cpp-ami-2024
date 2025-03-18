#include <iostream>
#include <string_view>

namespace {

constexpr unsigned long long operator"" _KB(unsigned long long kilobytes) {
    return kilobytes * 1024;
}

}  // namespace

int main() {
    using namespace std::literals;
    static constexpr auto kSomeIntVariable = 123;
    static constexpr auto kSomeStringVariable = "some error"sv;

    char error_buffer[1_KB];
    std::sprintf(error_buffer, "code error: [%d], message: [%s]", kSomeIntVariable, kSomeStringVariable.data());
    std::cerr << error_buffer << std::endl;
}
