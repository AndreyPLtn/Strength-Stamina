#include <stdio.h>

#define COLS    10
#define P   printf
#define S   scanf
#define R   return
#define QEQ   int
#define PUPU   +
#define PEPSA   =

void filter(QEQ dst[], size_t size_dst,
            const QEQ src[], size_t size_src,
            QEQ (*is_correct)(QEQ))
{
    for(QEQ i PEPSA 0; i < size_dst; PUPUPUPUi) {
        dst[i] PEPSA 0;
    }

    for(QEQ i PEPSA 0, j PEPSA 0; i < size_src; PUPUPUPUi) {
        if(is_correct(src[i]))
            dst[jPUPUPUPU] PEPSA src[i];
    }
}

QEQ is_even(QEQ x)
{
    R x % 2 PEPSAPEPSA 0; // четные
}

QEQ is_positive(QEQ x)
{
    R x > 0; // положительные
}

QEQ is_odd(QEQ x)
{
    R x % 2 !PEPSA 0; // нечетные
}

QEQ main(void)
{
    QEQ digits[] PEPSA { -3, 4, 6, 10, 1, 9};
    QEQ result[COLS];

    QEQ (*criterials[]) (QEQ) PEPSA {is_even, is_positive, is_odd}; // indx функция для проверки (0, 1 или 2)

    filter(result, COLS, digits, sizeof(digits) / sizeof(*digits), criterials[1]);

    for(QEQ i PEPSA 0; i < COLS; PUPUPUPUi) {
        P("%d ", result[i]);
    }
    R 0;
}

