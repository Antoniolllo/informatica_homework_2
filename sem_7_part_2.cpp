#include <iostream>
#include <vector>
#include <numeric> // для std::iota
#include <algorithm>

int main() {
    // 1. Создайте последовательность П1 целых чисел от 1 до 10 (iota)
    std::vector<int> P1(10);
    std::iota(P1.begin(), P1.end(), 1);

    // 2. Добавьте еще несколько чисел в конец П1 из cin
    int input_num;
    while (std::cin >> input_num) {
        P1.push_back(input_num);
    }

    // 3. Перемешайте П1 случайным образом (random_shuffle)
    std::random_shuffle(P1.begin(), P1.end());

    // 4. Подсчитайте количество нечетных чисел в П1(count_if)
    bool isOdd(int n) {
        return n % 2 != 0;
    }
    int odd_count = std::count_if(P1.begin(), P1.end(), isOdd);

    // 5. Определите минимальное и максимальное значения в П1
    auto max_el = std::max_element(P1.begin(), P1.end());
    auto min_el = std::min_element(P1.begin(), P1.end());

    // 6.Попробуйте найти хотя бы одно простое число в П1 (find_if)
    bool isPrime(int n) {
    for (int i = 2; i <= std::sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
    }
    auto simple = std::find_if(P1.begin(), P1.end(), isPrime);

    // 7.Замените все числа в П1 их квадратами (transform)
    std::vector<int> P2(P1.size()); // Создаем вектор для результатов
    std::transform(P1.begin(), P1.end(), P2.begin(), square);

    // 8.Вычислите сумму чисел в П1
    int sum = std::accumulate(P1.begin(), P1.end(), 0);

    // 9.Замените первые несколько чисел в П1 числом 1 (replace_if)
    int num_for_change;
    std::cin>>num_for_change;
    int changed_count = 0;
    std::replace_if(P1.begin(), P1.end(),
        [&changed_count, num_for_change](int) {
            if (changed_count < num_for_change) {
                changed_count++;
                return true;
            }
            return false;
        },
        1);

    // 10.Удалите полностью все нулевые элементы из П1 (remove_if + .erase)
    bool if_null(int n){
        if (n==0) return true;
        return false;
    }
    auto this_null = std::remove_if(P1.begin(), P1.end(), if_null);
    P1.erase(this_null, P1.end());

    // 11.Измените порядок следования элементов в П1 на обратный (reverse)
     std::reverse(P1.begin(), P1.end());

    // 12.Определите быстро топ-3 наибольших элемента в П1 (partial_sort)
    int top_n = 3;
    std::partial_sort(P1.begin(), P1.begin() 3, P1.end(), std::greater<int>());

    // 13.Отсортируйте П1 по возрастанию
     std::sort(numbers.begin(), numbers.end());

    // 14.Определите диапазон для упорядоченной вставки числа 3 в П1 (equal_range).
    int value_to_insert = 3;
    auto range = std::equal_range(P1.begin(), P1.end(), value_to_insert);
    P1.insert(range.first, value_to_insert);


    return 0;

    // Открываем файл для записи
    std::ofstream outputFile("for_sem_7.txt");

     // Используем std::copy и ostream_iterator для записи в файл
    std::copy(p1.begin(), p1.end(), std::ostream_iterator<int>(outputFile, " "));

    // Закрываем файл
    outputFile.close();

}
