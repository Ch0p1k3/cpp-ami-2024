#include <vector>
#include <string>

std::vector<std::string> Split(const std::string_view s, std::string_view delimiter = " ") {
    if (s.empty()) {
        return {};
    }

    std::vector<std::string> result;
    size_t end = s.find(delimiter);
    size_t start = 0;
    while (end != std::string_view::npos) {
        auto current = s.substr(start, end - start);
        result.push_back(std::string(current));
        start = end + delimiter.size();
        end = s.find(delimiter, start);
    }
    result.push_back(std::string(s.substr(start)));
    return result;
}
