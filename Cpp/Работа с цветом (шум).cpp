#include <iostream>
#include <ctime>
#include <windows.h>

int randomi = 0;
int x = 0;
int y = 0;
HWND hwnd = GetConsoleWindow();
HDC hdc = GetDC(hwnd);
int main() {
	using namespace std;
	//SetPixel (Дескриптор окна, X Y цвет(RGB) )
	while (true) {
		while (y < 100) {
			while (x < 100) {
				randomi = rand() % 2;
				if (randomi == 0) {
					SetPixel(hdc, x, y, RGB(255, 255, 1));
				}
				else {
					SetPixel(hdc, x, y, RGB(1, 1, 255));
				}
				x++;
			}
			x = 0;
			y++;
		}
		y = 0;
		x = 0;
		Sleep(1000);
	}
	//Вывели шум 
}
