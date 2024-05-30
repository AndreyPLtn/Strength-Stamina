#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <locale.h>

#define WIDTH 21
#define HEIGHT 14

char map[] =
"#####################\n"
"#                   #\n"
"#                   #\n"
"#                   #\n"
"#                   #\n"
"#                   #\n"
"#                   #\n"
"#                   #\n"
"#                   #\n"
"#                   #\n"
"#                   #\n"
"#                   #\n"
"#####################\n";

const int enemy_c = 5;
const int armor_c = 3;
bool isRun = true;
char player = 'O';
int p_pos_x = 5, p_pos_y = 2;
int score = 0;
int hp = 30, dmg = 1, arm = 0;
char enemy[enemy_c] = { 'E', 'E', 'E', 'E', 'E' };
int e_pos_x[enemy_c], e_pos_y[enemy_c];
char armor[armor_c] = { 'A', 'A', 'A' };
int a_pos_x[armor_c], a_pos_y[armor_c];

void setxy(int x, int y, char c) {
    map[y * WIDTH + x] = c;
}

void gotoxy(int x, int y) {
    COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void ShowConsoleCursor(bool showFlag) {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}

int main() {
    setlocale(LC_ALL, "Russian");
    using namespace std;

    ShowConsoleCursor(false);
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < enemy_c; ++i) {
        e_pos_x[i] = 1 + (rand() % (WIDTH - 3));
        e_pos_y[i] = 1 + (rand() % (HEIGHT - 2));
    }
    for (int i = 0; i < armor_c; ++i) {
        a_pos_x[i] = 1 + (rand() % (WIDTH - 3));
        a_pos_y[i] = 1 + (rand() % (HEIGHT - 2));
    }
    while (isRun) {
        for (int i = 0; i < enemy_c; ++i) {
            setxy(e_pos_x[i], e_pos_y[i], enemy[i]);
        }
        for (int i = 0; i < armor_c; ++i) {
            setxy(a_pos_x[i], a_pos_y[i], armor[i]);
        }
        setxy(p_pos_x, p_pos_y, player);
        gotoxy(0, 0);
        cout << "Score: " << score << endl;
        cout << "HP: " << hp << " " << endl;
        cout << "Damage: " << dmg << " " << endl;
        cout << "Arm: " << arm << " " << endl;
        cout << map;
        setxy(p_pos_x, p_pos_y, ' ');

        if (player != 'O') {
            gotoxy(WIDTH / 2 - 5, HEIGHT / 2);
            cout << ((player == 'W') ? "VICTORYYYY!!!" : "GAME OVAA");
            gotoxy(WIDTH / 2 - 7, HEIGHT / 2 + 1);
            cout << "Ur score: " << score;
            break; // Выход из цикла после вывода сообщения
        }
        char input = _getch();
        switch (tolower(input)) { // Обработка без учета регистра
        case 'a':
            if (p_pos_x > 1) {
                --p_pos_x;
            }
            break;
        case 'd':
            if (p_pos_x < WIDTH - 3) {
                ++p_pos_x;
            }
            break;
        case 'w':
            if (p_pos_y > 1) {
                --p_pos_y;
            }
            break;
        case 's':
            if (p_pos_y < HEIGHT - 2) {
                ++p_pos_y;
            }
            break;
        default:
            break;
        }
        for (int i = 0; i < enemy_c; ++i) {
            if (p_pos_x == e_pos_x[i] && p_pos_y == e_pos_y[i]) {
                enemy[i] = 'X';
                score += 10;
                hp = arm > 0 ? hp : hp - 10;
                if (hp <= 0) {
                    player = 'X';
                    isRun = false; // проигрыш
                }
            }
            if (p_pos_x == a_pos_x[i] && p_pos_y == a_pos_y[i]) {
                armor[i] = ' ';
                score += 5;
                arm = arm + 50 > 100 ? 100 : arm + 50;
            }
            if (hp <= 0) { // проверка на поражение
                player = 'X';
                isRun = false;
            }
        }
    }
}
