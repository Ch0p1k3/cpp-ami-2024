#include "string_view.hpp"
#include <cstring>

StringView::StringView(const std::string& s, size_t begin, size_t len)
    : StringView(s.c_str() + begin, len) {}

StringView::StringView(const char* s)
    : StringView(s, npos) {}

StringView::StringView(const char* s, size_t len)
    : begin_(s)
    , len_(len == npos ? strlen(s) : len) {}

char StringView::operator[](size_t i) const {
    return *(Data() + i);
}

const char* StringView::Data() const {
    return begin_;
}

size_t StringView::Size() const {
    return len_;
}

StringView StringView::Substr(size_t begin, size_t cnt) {
    return StringView(begin_ + begin, cnt);
}
