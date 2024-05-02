#include <iostream>
//#include <list>
//#include <cmath>
//#include <string>
//#include <fstream>
//#include <memory>
#include "pointND.h"

using namespace std;
//using std::cout;
//using std::cin;
//using std::endl;

int main(void)
{
    //provarka
    PointND pt(5);
    int cr[5] = {1, 2, 3, 4, 5};
    pt.set_coords(cr, 5);

    return 0;
}