// Source: https://github.com/siro53/compro_library
#line 1 "includes.cpp"
#include <iostream>
#line 2 "include/answer.hpp"

#line 2 "include/value.hpp"

constexpr int value = 42;
#line 4 "include/answer.hpp"

int answer() {
    return value;
}
#line 4 "includes.cpp"

int main() {
    std::cout << answer() << '\n';
}
