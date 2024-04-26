//********************Спартанский вариант****************
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main(void) {
	setlocale(LC_ALL, "RU");

	double a, f1, f2, fMax;
	scanf("%2f", &a);

	f1 = 5 * a + 12; // любые действительные числа для уравнения
	f2 = a * a - 34 * a + 1;// любые действительные числа для уравнения

	if (f1 > f2) {
		fMax = f1;
		}
	else {
		fMax = f2;
	}
	printf("%2f\n", &fMax);

	return 0;

}


//********************Полное решение с ыделением каждого логического шага в отдельную функцию****************
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#pragma warning(disable : 4996) //игнорирует ошибку C4996
//Прототипы функций
double Max(double, double);
double F1(double a);
double F2(double a);
//Main функция
int main(void) {
	setlocale(LC_ALL, "RU");

	double a, fMax;
	printf("Введите число a: ");
	scanf("%1.f\n", &a);

	fMax = Max(F1(a), F2(a));
	printf("Максимум из F1(a) и F2(a) является \n");
	printf("для a = %1.f равен %1.f\n", a, fMax);
	
	return 0;

}
//Вспомогательные функции F1 и F2
double F1(double a) {
	return (10 * a + 7);
}
double F2(double a) {
	return (a * a - 2 * a + 1);
}
//Рабочая функция FMax, которая проверяет и возвращает наибольший результат
double Max(double y1, double y2) {
	return (y1 > y2) ? y1 : y2;
}

