#include <stdio.h>

#define COLS    10
#define P   printf
#define S   scanf
#define R   return

void filter(int dst[], size_t size_dst,
            const int src[], size_t size_src,
            int (*is_correct)(int))
{
    for(int i = 0; i < size_dst; ++i) {
        dst[i] = 0;
    }

    for(int i = 0, j = 0; i < size_src; ++i) {
        if(is_correct(src[i]))
            dst[j++] = src[i];
    }
}

int is_even(int x)
{
    R x % 2 == 0;
}

int main(void)
{
    int digits[] = { -3, 4, 6, 10, 1, 9};
    int result[COLS];

    filter(result, COLS, digits, sizeof(digits) / sizeof(*digits), is_even);

    for(int i = 0; i < COLS; ++i) {
        P("%d ", result[i]);
    }
    R 0;
}

