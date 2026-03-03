#include <cstdio>
#include <cstdint>
#include <chrono>

int main() {
    using namespace std::chrono;
    const std::uint64_t iterations = 200000000ULL;
    double result = 1.0;
    double j = 4.0 - 1.0; // for i = 1 -> j = 3.0

    auto start = high_resolution_clock::now();

    std::uint64_t i = 0;
    const std::uint64_t n = iterations;

    // Manual unroll by 8 to reduce loop overhead while keeping exact operation order
    for (; i + 8 <= n; i += 8) {
        result -= 1.0 / j;       result += 1.0 / (j + 2.0); j += 4.0;
        result -= 1.0 / j;       result += 1.0 / (j + 2.0); j += 4.0;
        result -= 1.0 / j;       result += 1.0 / (j + 2.0); j += 4.0;
        result -= 1.0 / j;       result += 1.0 / (j + 2.0); j += 4.0;
        result -= 1.0 / j;       result += 1.0 / (j + 2.0); j += 4.0;
        result -= 1.0 / j;       result += 1.0 / (j + 2.0); j += 4.0;
        result -= 1.0 / j;       result += 1.0 / (j + 2.0); j += 4.0;
        result -= 1.0 / j;       result += 1.0 / (j + 2.0); j += 4.0;
    }

    for (; i < n; ++i) {
        result -= 1.0 / j;
        result += 1.0 / (j + 2.0);
        j += 4.0;
    }

    result *= 4.0;

    auto end = high_resolution_clock::now();
    double elapsed = duration_cast<duration<double>>(end - start).count();

    std::printf("Result: %.12f\n", result);
    std::printf("Execution Time: %.6f seconds\n", elapsed);

    return 0;
}