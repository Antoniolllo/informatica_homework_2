#include <iostream>
#include <vector>
#include <numeric>
#include <future>
#include <chrono>

// Последовательное скалярное произведение
template <typename It1, typename It2, typename T>
T simple_dot(It1 a, It1 end, It2 b, T sum = {}) {
    return std::inner_product(a, end, b, sum);
}

// Параллельное скалярное произведение
template <typename It1, typename It2, typename T>
T parallel_dot(It1 a, It1 end, It2 b, T sum = {}, int threads = 2) {
    int length = end - a;
    if (length < 10000 || threads <= 1) {
        return simple_dot(a, end, b, sum);
    }

    int block = length / threads;
    std::vector<std::future<T>> parts;

    for (int i = 0; i < threads; ++i) {
        auto start = a + i * block;
        auto finish = (i == threads - 1) ? end : start + block;

        parts.push_back(std::async([=] {
            T part_sum = 0;
            for (auto it = start; it != finish; ++it) {
                part_sum += (*it) * b[it - a];
            }
            return part_sum;
        }));
    }

    for (auto& f : parts) {
        sum += f.get();
    }

    return sum;
}

int main() {
    std::vector<int> x(1'000'000, 1), y(1'000'000, 2);

    // Замер времени для последовательной версии
    auto t1 = std::chrono::high_resolution_clock::now();
    int seq = simple_dot(x.begin(), x.end(), y.begin());
    auto t2 = std::chrono::high_resolution_clock::now();

    // Замер времени для параллельной версии
    auto t3 = std::chrono::high_resolution_clock::now();
    int par = parallel_dot(x.begin(), x.end(), y.begin());
    auto t4 = std::chrono::high_resolution_clock::now();

    auto seq_time = std::chrono::duration<double>(t2 - t1).count();
    auto par_time = std::chrono::duration<double>(t4 - t3).count();

    std::cout << "Последовательно: " << seq << " (" << seq_time << " сек)\n";
    std::cout << "Параллельно: " << par << " (" << par_time << " сек)\n";
    std::cout << "Ускорение: " << seq_time / par_time << "x\n";

}
