#include <cstdio>
#include <chrono>
#include <cstdint>

int main() {
    const std::int64_t iterations = 200000000LL;
    double result = 1.0;

    // denominators for i = 1: 4*1 - 1 = 3, 4*1 + 1 = 5
    double d1 = 3.0;
    double d2 = 5.0;

    auto start = std::chrono::high_resolution_clock::now();

    const std::int64_t unroll = 8;
    std::int64_t blocks = iterations / unroll;
    for (std::int64_t b = 0; b < blocks; ++b) {
        // unrolled 8 iterations, preserving per-iteration order (subtract then add)
        result -= 1.0 / d1; result += 1.0 / d2; d1 += 4.0; d2 += 4.0;
        result -= 1.0 / d1; result += 1.0 / d2; d1 += 4.0; d2 += 4.0;
        result -= 1.0 / d1; result += 1.0 / d2; d1 += 4.0; d2 += 4.0;
        result -= 1.0 / d1; result += 1.0 / d2; d1 += 4.0; d2 += 4.0;
        result -= 1.0 / d1; result += 1.0 / d2; d1 += 4.0; d2 += 4.0;
        result -= 1.0 / d1; result += 1.0 / d2; d1 += 4.0; d2 += 4.0;
        result -= 1.0 / d1; result += 1.0 / d2; d1 += 4.0; d2 += 4.0;
        result -= 1.0 / d1; result += 1.0 / d2; d1 += 4.0; d2 += 4.0;
    }

    std::int64_t rem = iterations % unroll;
    for (std::int64_t r = 0; r < rem; ++r) {
        result -= 1.0 / d1;
        result += 1.0 / d2;
        d1 += 4.0;
        d2 += 4.0;
    }

    auto end = std::chrono::high_resolution_clock::now();

    double final_result = result * 4.0;
    double elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();

    std::printf("Result: %.12f\n", final_result);
    std::printf("Execution Time: %.6f seconds\n", elapsed);

    return 0;
}