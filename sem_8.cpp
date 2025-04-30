#include <iostream>
#include <utility>

// �������, ������� ��������� ������ ������� � ���������, �������� � � ���������� ���������
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
