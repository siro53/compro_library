struct random_number_generator {
    mt19937 mt;
    random_number_generator():mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    int operator()(int a, int b) {
        uniform_int_distribution<int> dist(a, b - 1);
        return dist(mt);
    }
    int operator()(int b) {
        return (*this)(0, b);
    }
};
