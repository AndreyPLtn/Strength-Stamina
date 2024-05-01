#include <iostream>

using namespace std;

class Log {
    unsigned id = 0; // приватное поле id
public: 
    Log(unsigned id_log) : id(id_log) // инициализация поля переданным аргументом id_log
        {
            cout << "Log: constructor" << endl;
        }
    ~Log() // деструктор
        {
            cout << "Log: destructor" << endl;
        }
};

class Point { // Класс с точками x, y и объектом типа Log 
    int x {-1}; 
    int y {-1};
    Log lg {9}; // если не инициализировать объект - будет ошибка

public:
    Point() : x(0), y(0) // конструктор, инициализирующий x и y нулями
        {
            cout << "Point: constructor_1" << endl;
        }
    Point(int a, int b) : x(a), y(b), lg(123) // инициализация (x, y) переданными значениями и объект Log lg числом 123
        {
            cout << "Point: constructor_2" << endl;
        }
    ~Point() // деструктор
        {
            cout << "Point: destructor" << endl;
        }
    
    void get_coords(int& a, int& b) // геттер
        {
            a = x;
            b = y;
        }
    void set_coords(int a, int b) // сеттер
        {
            x = a;
            y = b;
        }
};

int main(void)
{
    //chekers
    Point pt_1(1, 2);
    
    return 0;
}
