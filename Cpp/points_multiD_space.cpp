#include <iostream>

using namespace std;

class PointND {
    unsigned total {0};
    int *coords {nullptr};
public:
    PointND() : total(0), coords(nullptr) // инициализация точки с нулевой размерностью и пустыми координатами
    { }
    PointND(unsigned sz) : total(sz) // создание точки с указанной размерностью и инициализация координаты нулями.
    {
        coords = new int[total] {0};
    }
    PointND(int* cr, unsigned len) : total(len) // создание точку с координатами, переданными в массиве cr, длиной len
    {
        set_coords(cr, len);
    }
    PointND(const PointND& other) : PointND(other.coords, other.total) // копирование данных из точки other.
    { } //делегирующий конструктор

    ~PointND() // деструктор освобождает динамически выделенную память для массива координат
    {
        delete[] coords;
    }

    unsigned get_total() { return total; }
    const int* get_coords() { return coords; }
    void set_coords(int* cr, unsigned len)
    {
        for(unsigned i = 0; i < total; ++i)
            coords[i] = (i < len) ? cr[i] : 0;
    }

    const PointND& operator=(const PointND& other) // корректное освобождение и выделение памяти
                                        //при присваивании одного другому объектов в классе PointND
    {
        if(this == &other)
            return *this;
            
        delete[] coords;
        total = other.total;
        coords = new int[total];
        set_coords(other.coords, total);

        return *this;
    }

};

int main(void)
{
    //chekers
    PointND pt(5);
    PointND pt2;

    pt2 = pt2;
    return 0;
}
