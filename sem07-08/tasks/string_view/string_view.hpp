#pragma once

#include <cstring>
#include <string>

class StringView {
public:
    StringView(const std::string& s, size_t begin = 0, size_t len = npos);

    StringView(const char* s);

    StringView(const char* s, size_t len);

    char operator[](size_t i) const;

    const char* Data() const;

    size_t Size() const;

    StringView Substr(size_t begin, size_t cnt = npos);

public:
    static const auto npos = std::string::npos;

private:
    const char* begin_;
    size_t len_;
};
