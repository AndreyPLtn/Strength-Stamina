#include <stdio.h>

int main() {
    float celsius, fahrenheit;

    printf("Таблица соответствия температур по Цельсию и Фаренгейту\n");
    printf("Цельсий-Фаренгейт\n");
    printf("----------------\n");

    

    for(celsius = -20; celsius <= 40; celsius += 5) {
        fahrenheit = (celsius * 9/5) + 32;
        printf("%6.2f | %6.2f\n", celsius, fahrenheit);
    }

    return 0;
}
