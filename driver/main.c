
#include <stdio.h>
#include "../src/gc.h"
///#include "../src/header.h"


int main(int argc, char* argv[]) {
    
    heap_t* heap = h_init(1, true, 0.5);



    printf("\nThis main is running.\nCongrats!\n\n");

    h_delete(heap);
    return 0;
}
