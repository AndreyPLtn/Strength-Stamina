#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main(void) {
	setlocale(LC_ALL, "RU");

	int a = 10, b = 15;
	int c;
	_s_scanf("%d %d", &a, &b);
	c = (a - b);
	c = (c < 0) ? -c : c;
	printf("%d", c);
	return 0;
	
}
