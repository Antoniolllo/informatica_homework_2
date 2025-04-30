#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <numeric>
#include <chrono>

std::mutex result_mutex;

// Функция, выполняющая суммирование части вектора
void sum_part(const std::vector<int>& vec, int start, int end, int& total) {
    int part_sum = std::accumulate(vec.begin() + start, vec.begin() + end, 0);
    std::lock_guard<std::mutex> lock(result_mutex);
    total += part_sum;
}

// Функция параллельного суммирования
int parallel_sum(const std::vector<int>& vec, int threads_count = 4) {
    int total = 0;
    int part_size = vec.size() / threads_count;
    std::vector<std::thread> threads;

    for (int i = 0; i < threads_count; ++i) {
        int start = i * part_size;
        int end = (i == threads_count - 1) ? vec.size() : (i + 1) * part_size;
        threads.emplace_back(sum_part, std::ref(vec), start, end, std::ref(total));
    }

    for (auto& t : threads) {
        t.join();
    }

    return total;
}

int main() {
    std::vector<int> data(1000000, 1);

    // Параллельное суммирование
    auto start = std::chrono::high_resolution_clock::now();
    int sum = parallel_sum(data);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Sum: " << sum << " Time: " << elapsed.count() << "s\n";

    return 0;
}
