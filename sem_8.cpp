#include <iostream>
#include <utility>

// Функция, которая принимает другую функцию и аргументы, вызывает её и игнорирует результат
template <typename Func, typename... Args>
void callAndIgnore(Func&& func, Args&&... args) {
    std::forward<Func>(func)(std::forward<Args>(args)...);
}

void printSum(int a, int b) {
    std::cout << "Sum: " << a + b << std::endl;
}

int multiplication(int x, int y) {
    return x * y;
}

int main() {
    callAndIgnore(printSum, 3, 4);

    callAndIgnore(multiplication, 5, 6);

    callAndIgnore([](const std::string& s) { std::cout << s << std::endl; }, "Hello!");

    return 0;
}
