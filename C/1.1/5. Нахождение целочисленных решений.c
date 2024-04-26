#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#pragma warning(disable : 4996) //игнорирует ошибку C4996

int main(void) {
	setlocale(LC_ALL, "RU");

	int a, b, n;
	int c;

	printf("Введите числа a, b и c: \n");
	scanf("%d %d %d\n", &a, &b, &c);

	int solutions = 0;
	for (int x = 0; x < 100; x++) {
		if ((a * x) + b == c) {
			solutions++;
		}
	}

	printf("Количество целочисленных решений: %d\n", &solutions);

	return 0;

}
