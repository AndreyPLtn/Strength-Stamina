#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <math.h>
using namespace std;

void goToXY(int x, int y) // координаты
{
    COORD coord = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

const int hurdleCount = 4;

class Flappy_bird { // характеристики коорд класса
    int hurdlePos[hurdleCount][2];
    int screenWidth = 79;
    int screenHeight = 25;
    int hurdleGap = 8;
    int betweenHurdleGap;

    int birdx = 17;
    int birdy = 15;
    int jump = 4;
    int score = 0;

public:
    Flappy_bird() 
    {
        srand(time(NULL));
        betweenHurdleGap = (screenWidth / hurdleCount) + 8;
        for (int i = 0; i < hurdleCount; i++)
        {
            hurdlePos[i][0] = betweenHurdleGap * (i + 1);

            int breakPos = rand() % (screenHeight / 3) + hurdleGap;
            hurdlePos[i][1] = breakPos;
        }
    }

    void printHurdle() // вывод препятствия
    {
        int count = 0;
        for (int i = 0; i < hurdleCount; i++) {
            for (int j = 0; j < screenHeight; j++) {

                if (hurdlePos[i][1] == j) count = hurdleGap;

                if (count == 0) {
                    if (hurdlePos[i][0] < screenWidth) {
                        goToXY(hurdlePos[i][0] + 1, j);

                        goToXY(hurdlePos[i][0], j);
                        cout << i;
                    }
                }
                else {
                    if ((count == 1 || count == hurdleGap) && hurdlePos[i][0] < screenWidth) {
                        if (hurdlePos[i][0] + 1 > 0) {
                            goToXY(hurdlePos[i][0] + 1, j);
                            cout << "  ";
                        }
                        if (hurdlePos[i][0] - 1 > 0) {
                            goToXY(hurdlePos[i][0] - 1, j);
                            cout << "===";
                        }
                    }

                    count--;
                }
            }

            hurdlePos[i][0]--;

            if (hurdlePos[i][0] == -1) {
                int prev;
                if (i == 0)
                    prev = hurdleCount - 1;
                else
                    prev = i - 1;

                hurdlePos[i][0] = hurdlePos[prev][0] + betweenHurdleGap;

                int breakPos = rand() % (screenHeight / 3) + hurdleGap;
                hurdlePos[i][1] = breakPos;

                for (int i = 0; i < screenHeight; i++) {
                    goToXY(0, i);
                    cout << " ";
                }

            }
        }
    }

    bool collisionCheck() { // проверка столкновения
        if (birdy == 0 || birdy + 3 == screenHeight) return true;

        for (int i = 0; i < hurdleCount; i++) {
            if (
                hurdlePos[i][0] == birdx &&
                (
                    birdy >= hurdlePos[i][1] ||
                    birdy + 3 <= (hurdlePos[i][1] + hurdleGap)
                    )
                ) {
                score++;
            }

            if (hurdlePos[i][0] >= birdx - 5 &&
                hurdlePos[i][0] <= birdx &&
                (
                    birdy <= hurdlePos[i][1] ||
                    birdy + 3 >= (hurdlePos[i][1] + hurdleGap)
                    )
                ) {
                return true;
            }

        }
        return false;
    }

    void clearBird() // убирает птичку с консоли
    {
        goToXY(birdx - 5, birdy);
        cout << "  ";
        goToXY(birdx - 5, birdy + 1);
        cout << "     ";
        goToXY(birdx - 5, birdy + 2);
        cout << "       ";
    }
    void printScore() // вывод очка(ов)
    {
        goToXY(0, screenHeight + 4);
        cout << "Score: " << score;
    }
    void printBird() // показывает птичку
    {
        goToXY(birdx - 5, birdy);    cout << " __";
        goToXY(birdx - 5, birdy + 1);   cout << "/-/0\\";
        goToXY(birdx - 5, birdy + 2);       cout << "\\_\\-/";
    }

    void printRoad() { // вывод дороги
        for (int i = 0; i <= screenWidth; i++) {
            goToXY(i, screenHeight);    cout << "_";
            goToXY(i, screenHeight + 1);  cout << "/";
            goToXY(i, screenHeight + 2);  cout << "=";
        }
    }


    void play() // метод play содержит основной игровой процесс
    {
        printRoad();
        int someDelay = 0;
        while (true) {
            if (GetAsyncKeyState(VK_SPACE)) {
                birdy -= jump;
            }

            printHurdle();
            printBird();
            printScore();

            if (collisionCheck()) break;

            Sleep(100);
            clearBird();
            birdy += 1;
        }
    }

};

int main() {
    while (true) { // бесконечный цикл игры, который заканчивает вводом N / n
        Flappy_bird fb;
        fb.play();
        goToXY(30, 30);
        cout << "Do you want to play again? (Y/N)";

        char ch;
        cin >> ch;
        if (ch == 'N' || ch == 'n') {
            break;
        }
        system("cls");
    }
    return 0;
}
