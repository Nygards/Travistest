#include "code_convention.h" // Always include own header file
#include "other_file.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MY_LIMIT 10    // define values to avoid magical values
#define OTHER_VALUE 4



char *hello_name(char *name) {
    return "";
}

bool bigger_then(int a, int b) {       // snake casing (small letters and _)
    if (a < b) {
        return true;
    } else {
        return false;
    }
}


void *get_pointer() {
    return NULL;
}


int main(int argc, char **argv) {
    while (int i < MY_LIMIT) {
        i++;
    }
}
