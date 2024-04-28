#include <iostream>

using std::cout;
using std::endl;

#ifdef __cplusplus
extern "C" {
#endif
void show_msg(const char* msg)
{
    puts("SOOBWENIE");
    puts(msg);
    puts("POSLEDNEE SOOBWENIE");
}
#ifdef __cplusplus
}
#endif

int module(int x)
{
    cout << "module_int(int)" << endl;
    if(x >= -10 && x <= 10)
        return (x > 0) ? x : -x;
    return x;
}

double module(double x)
{
    cout << "module_double(double)" << endl;
    if(x >= -10 && x <= 10)
        return (x > 0) ? x : -x;
    return x;
}

int main()
{
    // proverka
    show_msg("show msg");

    double res_1 = module(-0.5f);
    int res_2 = module(-0.5);
    double res_3 = module(-5);
    int res_4 = module((short)-5);


    return 0;
}
