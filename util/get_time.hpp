inline double get_time() {
    const double ticks_per_sec = 2500000000;
    uint32_t lo, hi;
    asm volatile("rdtsc" : "=a"(lo), "=d"(hi));
    return (((uint64_t)hi << 32) | lo) / ticks_per_sec;
}


