#include <iostream>
#include <sstream>
#include <string_view>

int main() {
    using namespace std::literals;
    static constexpr auto kSomeIntVariable = 123;
    static constexpr auto kSomeStringVariable = "some error"sv;

    std::ostringstream error_string_builder;
    error_string_builder
        << "code error: [" << kSomeIntVariable << "], "
        << "message" << "[" << kSomeStringVariable << "]";
    std::cerr << error_string_builder.str() << std::endl;
}
