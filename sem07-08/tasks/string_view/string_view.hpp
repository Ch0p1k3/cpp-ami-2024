#pragma once

#include <cstring>
#include <stdexcept>
#include <string>

class StringView {
public:
    StringView(const std::string& s, size_t beg = 0, size_t len = npos)
        : begin_(s.c_str() + beg)
        , len_(len == npos ? s.size() - beg : len) {
    }

    StringView(const char* s)
        : begin_(s)
        , len_(std::strlen(s)) {
    }

    StringView(const char* s, size_t len)
        : begin_(s)
        , len_(len) {
    }

    char operator[](size_t i) const {
        if (i > len_) {
            throw std::invalid_argument("i > len");
        }
        return *(begin_ + i);
    }

    const char* Data() const {
        return begin_;
    }

    size_t Size() const {
        return len_;
    }

public:
    static const auto npos = std::string::npos;

private:
    const char* begin_;
    size_t len_;
};
