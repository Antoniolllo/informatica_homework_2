#include <iostream>
#include <vector>
#include <numeric> // ��� std::iota
#include <algorithm>

int main() {
    // 1. �������� ������������������ �1 ����� ����� �� 1 �� 10 (iota)
    std::vector<int> P1(10);
    std::iota(P1.begin(), P1.end(), 1);

    // 2. �������� ��� ��������� ����� � ����� �1 �� cin
    int input_num;
    while (std::cin >> input_num) {
        P1.push_back(input_num);
    }

    // 3. ����������� �1 ��������� ������� (random_shuffle)
    std::random_shuffle(P1.begin(), P1.end());

    // 4. ����������� ���������� �������� ����� � �1(count_if)
    bool isOdd(int n) {
        return n % 2 != 0;
    }
    int odd_count = std::count_if(P1.begin(), P1.end(), isOdd);

    // 5. ���������� ����������� � ������������ �������� � �1
    auto max_el = std::max_element(P1.begin(), P1.end());
    auto min_el = std::min_element(P1.begin(), P1.end());

    // 6.���������� ����� ���� �� ���� ������� ����� � �1 (find_if)
    bool isPrime(int n) {
    for (int i = 2; i <= std::sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
    }
    auto simple = std::find_if(P1.begin(), P1.end(), isPrime);

    // 7.�������� ��� ����� � �1 �� ���������� (transform)
    std::vector<int> P2(P1.size()); // ������� ������ ��� �����������
    std::transform(P1.begin(), P1.end(), P2.begin(), square);

    // 8.��������� ����� ����� � �1
    int sum = std::accumulate(P1.begin(), P1.end(), 0);

    // 9.�������� ������ ��������� ����� � �1 ������ 1 (replace_if)
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

    // 10.������� ��������� ��� ������� �������� �� �1 (remove_if + .erase)
    bool if_null(int n){
        if (n==0) return true;
        return false;
    }
    auto this_null = std::remove_if(P1.begin(), P1.end(), if_null);
    P1.erase(this_null, P1.end());

    // 11.�������� ������� ���������� ��������� � �1 �� �������� (reverse)
     std::reverse(P1.begin(), P1.end());

    // 12.���������� ������ ���-3 ���������� �������� � �1 (partial_sort)
    int top_n = 3;
    std::partial_sort(P1.begin(), P1.begin() 3, P1.end(), std::greater<int>());

    // 13.������������ �1 �� �����������
     std::sort(numbers.begin(), numbers.end());

    // 14.���������� �������� ��� ������������� ������� ����� 3 � �1 (equal_range).
    int value_to_insert = 3;
    auto range = std::equal_range(P1.begin(), P1.end(), value_to_insert);
    P1.insert(range.first, value_to_insert);


    return 0;

    // ��������� ���� ��� ������
    std::ofstream outputFile("for_sem_7.txt");

     // ���������� std::copy � ostream_iterator ��� ������ � ����
    std::copy(p1.begin(), p1.end(), std::ostream_iterator<int>(outputFile, " "));

    // ��������� ����
    outputFile.close();

}
