#include <stdio.h>

#include "my_folder.h"

int main() {
    printf("start appn");

    // проверка
    mf_info_t track1 = {1, 2, 3};
    mf_add(&track1);

    mf_info_t track2;
    mf_get_info(0, &track2);

    mf_delete(0);

    mf_reset();

    return 0;
}
