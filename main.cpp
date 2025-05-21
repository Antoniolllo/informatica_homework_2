#include <iostream>
#include "time.h"  // Подключаем наш заголовочный файл

int main() {
    double hours;
    std::cout << "Введите количество часов: ";
    std::cin >> hours;

    std::cout << hours << " часов = " << hours_to_minutes(hours) << " минут\n";
    std::cout << hours << " часов = " << hours_to_seconds(hours) << " секунд\n";

    return 0;
}
