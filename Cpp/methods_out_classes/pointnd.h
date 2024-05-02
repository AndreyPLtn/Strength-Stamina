#ifndef _POINTND_H_
#define _POINTND_H_

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
    

    const PointND& operator=(const PointND& other);

    unsigned get_total() { return total; }
    const int* get_coords() { return coords; }
    void set_coords(int* cr, unsigned len);

    ~PointND() { delete[] coords; } // деструктор освобождает динамически выделенную память для массива координат
};

#endif