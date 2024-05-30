#include <iostream>
#include <vector>

int main() {
    setlocale(LC_ALL, "Russian");

    int numVisitors;
    double hourlyRate;
    std::cout << "Введите стоимость одного часа тренировки: ";
    std::cin >> hourlyRate;

    std::cout << "Введите количество посетителей спортзала: ";
    std::cin >> numVisitors;

    std::vector<int> hours(numVisitors);
    double totalCost = 0;

    for (int i = 0; i < numVisitors; ++i) {
        std::cout << "Введите количество часов, проведенных посетителем " << (i + 1) << ": ";
        std::cin >> hours[i];
        totalCost += hours[i] * hourlyRate;
    }

    std::cout << "Общая сумма, которую посетители заплатили за тренировки: " << totalCost << " рублей." << std::endl;

    return 0;
}
