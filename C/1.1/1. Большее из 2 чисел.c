#include <stdio.h>
#include <locale.h>

	

int Max(int, int);

int main(void) {
	setlocale(LC_ALL, "RU");
	int a, b, abMax;

	printf("Введите целые a и b числа: ");
	scanf_s("%d %d", &a, &b);
	abMax = Max(a, b);
	printf("Max(%d %d) = %d\n", a, b, abMax);

	return 0;
}

int Max(int x, int y) {
	int z;
	z = (x > y) ? x : y;
	return z;
}
