#include <vector>

void MoveZeros(std::vector<int>& arr) {
    std::size_t cnt = 0;
    for (std::size_t i = 0; i < arr.size(); ++i) {
        const auto e = arr[i];
        if (e == 0) {
            continue;
        }
        arr[cnt++] = e;
    }
    arr.resize(cnt);
}
