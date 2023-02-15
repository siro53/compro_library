#pragma once

template <typename T> T ceil_div(T a, T b) {
    if(b < 0) a = -a, b = -b;
    return (a >= 0 ? (a + b - 1) / b : a / b);
}

template <typename T> T floor_div(T a, T b) {
    if(b < 0) a = -a, b = -b;
    return (a >= 0 ? a / b : (a - b + 1) / b);
}