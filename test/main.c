#include <stdio.h>

#include "my_folder.h"

int main() {
	printf("start app");
	
    
    mf_info_t track_1 = {1, 2, 3};
    mf_add(&track_1);

    mf_info_t track_2;
    mf_get_info(0, &track_2);
    
    mf_delete(0);

    return 0;
}