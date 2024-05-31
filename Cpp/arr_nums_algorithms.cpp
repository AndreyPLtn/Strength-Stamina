//processing and analyzing data in an array of numbers using standard C++ algorithms
#include <iostream>
#include <vector>
#include <algorithm>

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;
    if (n <= 0) {
        std::cout << -1 << std::endl;
        return -1;
    }

    std::vector<int> array(n);
    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

    int pairs;
    std::cout << "Введите количество пар: ";
    std::cin >> pairs;
    if (pairs <= 0) {
        std::cout << -1 << std::endl;
        return -1;
    }

    while (pairs--) {
        int first, last;
        std::cout << "Введите первое и последнее число диапазона: ";
        std::cin >> first >> last;

        auto lower = std::lower_bound(array.begin(), array.end(), first);
        auto upper = std::upper_bound(array.begin(), array.end(), last);

        if (lower == array.end() || *lower > last) {
            std::cout << 0 << std::endl;
            continue;
        }

        int primeCount = 0;
        for (auto it = lower; it != upper; ++it) {
            if (isPrime(*it)) {
                ++primeCount;
            }
        }

        std::cout << primeCount << std::endl;
    }

    return 0;
}
