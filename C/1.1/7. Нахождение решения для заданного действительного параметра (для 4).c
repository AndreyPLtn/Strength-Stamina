#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#pragma warning(disable : 4996) //игнорирует ошибку C4996
//Прототипы функций
double Max(double, double, double, double);
double F1(double a);
double F2(double a);
double F3(double x);
double F4(double x);
//Main функция
int main(void) {
	setlocale(LC_ALL, "RU");

	double a, fMax;
	printf("Введите число a: ");
	scanf("%1.f\n", &a);

	fMax = Max(F1(a), F2(a), F3(a), F4(a) );
	printf("Максимум из F1(a), F2(a), F3(a), F4(a) является \n");
	printf("для a = %1.f равен %1.f\n", a, fMax);
	
	return 0;

}
//Вспомогательные функции 
double F1(double x) {
	return (x * x - 3);
}
double F2(double x) {
	return (5 * (x - 12 )*(x + 2 ));
}
double F3(double x) {
	return (17 * x + 1);
}
double F4(double x) {
	return ((x+1)*(x+2)*(x-3)-10);
}
//Рабочая функция FMax, которая проверяет и возвращает наибольший результат
double Max(double y1, double y2, double y3, double y4) {
	return (y1 > y2) ? y1 : y2;
	return (y3 > y4) ? y3 : y4;
}

//Эта функция вычисляет максимальное значение среди четырёх функций F1, F2, F3 и F4,
//передавая им общее значение переменной “a”.
//Затем она выводит значение “a” и найденное максимальное значение на экран.
