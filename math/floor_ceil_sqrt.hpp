template<class T>
T floor_sqrt(T x) {
    assert(x >= 0);
    T ok = 0, ng = 1;
    while(ng * ng <= x) ng *= 2;
    while(ng - ok > 1) {
        T mid = (ok + ng) / 2;
        (mid * mid <= x ? ok : ng) = mid;
    }
    return ok;
}

template<class T>
T ceil_sqrt(T x) {
    assert(x >= 0);
    if(x == 0) return (T)0;
    T ok = 1, ng = 0;
    while(ok * ok <= x) ok *= 2;
    while(ng - ok > 1) {
        T mid = (ok + ng) / 2;
        (mid * mid >= x ? ok : ng) = mid;
    }
    return ok;
}