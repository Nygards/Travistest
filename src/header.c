#include <string.h>
#include <stdint.h>
#include <assert.h>
#include "header.h"

#define FLAG_FILTER (intptr_t) 3
#define FORMAT_FLAG (intptr_t) 0
#define FORWARD_FLAG (intptr_t) 1
#define DATA_FLAG (intptr_t) 2

struct head {
    void* value;
};




size_t header_struct_size() {
    return sizeof(struct head);
}


bool header_is_format_string(header* header) {

    intptr_t head = (intptr_t) header->value;
    intptr_t head_flag = head & FLAG_FILTER;

    return head_flag == FORMAT_FLAG;
}

void header_set_format_string(heap_t* heap, header* head, char* format_string){
    int length = strlen(format_string)+1;
    char* copy = h_alloc_data(heap, length*sizeof(char));

    for (int i = 0; i < length ; ++i) {
        copy[i] = format_string[i];
    }

    head->value = copy;
}

char* header_get_format_string(header* head) {
    if (header_is_format_string(head)) {
        return head->value;
    }
    return NULL;
}




bool header_is_forward(header* header){
    intptr_t head = (intptr_t) header->value;
    intptr_t head_flag = head & FLAG_FILTER;

    return head_flag == FORWARD_FLAG;
}

void header_set_forward(header* head, void* forward_adress) {
    if (!header_is_forward(head)) {
        intptr_t adress = (intptr_t) forward_adress;
        intptr_t flag = 1;

        head->value = (void*) (adress | flag);
    }
}

void* header_get_forward(header* head) {
    if(header_is_forward(head)) {
        intptr_t adress = (intptr_t) head->value;
        adress >>= 2;
        adress <<= 2;
        return (void*) adress;
    }
    return NULL;
}




bool header_is_data(header* header){
    intptr_t head = (intptr_t) header->value;
    intptr_t head_flag = head & FLAG_FILTER;

    return head_flag == DATA_FLAG;
}


void header_set_data(header* head, size_t size) {
    intptr_t adress = 0;
    adress = adress | size;
    adress <<= 2;
    adress |= 2;
    head->value =(void*) adress;
}

size_t header_get_allocated_size(header* head) {
    if (header_is_data(head)) {
        size_t size = 0;
        intptr_t value = ((intptr_t) head->value) >> 2;
        return size |= value;
    }
    else if (header_is_format_string(head)) {
        char* format_string = header_get_format_string(head);
        size_t size = 0;
        for (int i = 0;format_string[i] !='\0'; ++i) {
            if (format_string[i] == 'i') {
                size += sizeof(int);
            }
            else if (format_string[i] == 'f') {
                size += sizeof(float);
            }
            else if (format_string[i] == 'c') {
                size += sizeof(char);
            }
            else if (format_string[i] == 'l') {
                size += sizeof(long);
            }
            else if (format_string[i] == 'd') {
                size += sizeof(double);
            }
            else if (format_string[i] == '*') {
                size += sizeof(void*);
            }
            else{
                assert(false);
            }
        }
        return size;
    }
    return -1;
}
