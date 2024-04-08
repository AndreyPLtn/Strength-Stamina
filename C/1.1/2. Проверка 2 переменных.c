#include <stdio.h>
#include <locale.h> // Подключение прочих языков

#pragma warning(suppress : 4996) // позволяет включить устаревшие функции

int main() { //программа на проверку >, < или = чисел
    setlocale(LC_ALL, "Rus");
    int a, b;

    printf("Введите два числа: ");
    scanf_s("%d\n%d", &a, &b);

    if (a > b) {
        printf("%d больше, чем %d.\n", a, b);
    }
    else if (a < b) {
        printf("%d меньше, чем %d.\n", a, b);
    }
    else {
        printf("Два числа равны: %d = %d.\n", a, b);
    }

    return 0;
}
