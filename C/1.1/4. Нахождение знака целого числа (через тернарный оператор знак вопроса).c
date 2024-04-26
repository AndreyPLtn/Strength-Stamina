#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int sign(int a);

int main(void) {
	setlocale(LC_ALL, "RU");

	int num = -10;
	int signNum = sign(num);
	printf("%d имеет знак %d.\n", num, signNum);


	return 0;

}

int sign(int a) {
	int sign = (a > 0) ? 1 : ((a < 0) ? -1 : 0);
}
