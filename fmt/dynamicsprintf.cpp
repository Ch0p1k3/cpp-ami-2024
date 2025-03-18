#include <cstdarg>
#include <iostream>
#include <string_view>

namespace {

std::string Sprintf(const char* format, ...) {
    va_list args;

    // Измеряем нужный размер
    va_start(args, format);
    int size = std::vsnprintf(nullptr, 0, format, args) + 1; // +1 для завершающего нуля
    va_end(args);

    // Создаем строку нужного размера
    std::string result(size, '\0');

    // Форматируем строку в выделенный буфер
    va_start(args, format);
    std::vsnprintf(&result[0], size, format, args);
    va_end(args);

    // Удаляем завершающий нулевой символ, который добавлен для snprintf
    result.resize(size - 1);

    return result;
}

}  // namespace

int main() {
    using namespace std::literals;
    static constexpr auto kSomeIntVariable = 123;
    static constexpr auto kSomeStringVariable = "some error"sv;

    std::cerr << Sprintf("code error: [%d], message: [%s]", kSomeIntVariable, kSomeStringVariable.data()) << std::endl;
}
