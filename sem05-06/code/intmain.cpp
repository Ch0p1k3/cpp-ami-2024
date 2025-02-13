#include <iostream>

int main(int argc, const char* argv[], const char* envs[]) {
    size_t i = 0;
    auto env = envs[i];
    while (env != nullptr) {
        std::cout << envs[i] << std::endl;
        ++i;
        env = envs[i];
    }
}
