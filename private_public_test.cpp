#include <iostream>
#include <math.h>

using std::cout;
using std::endl;

class Point2D {
private:
    int x, y;
public:
    void set_coords(int a, int b) {
        x = a; y = b;
    }
    void get_coords(int& a, int& b) {
        a = x; b = y;
    }

    bool set_coords_range(int a, int b, int min_coord = 0, int max_coord = 100) {
        if(a < min_coord || a > max_coord || b < min_coord || b > max_coord)
            return false;

        set_coords(a, b);
        return true;
    }

    double length_to(const Point2D& pt) {
        return sqrt((x-pt.x)*(x-pt.x) + (y-pt.y)*(y-pt.y));
    }
};

int main()
{
    // proverka
    Point2D pt, endp;

    pt.set_coords(1, 2);
    endp.set_coords(13, 21);

    double len = pt.length_to(endp);
    cout << len << endl;

    return 0;
}
