#include <iostream>

#define если if

#define то {

#define конец }

#define печать(X) std::cout<<X<<std::endl;

#ifndef TEST_FLAG

int Sq(int i);

#else

long long Sq(long long i);

#endif

int32_t main() {
    std::cout << Sq(2) << std::endl;

    если (0 == 0) то печать("Да") конец
}
