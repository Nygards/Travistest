#include "heap.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>


//#define END(h) h.start+h.size*2
#define START_INDEX 0
#define MIDDLE_INDEX 1
#define EMPTY_INDEX 2

//~ struct heap {
    //~ int size;
    //~ void *bucket[3];
    //~ void *frontier;
    //~ bool *alloc_map[2];
//~ };


heap_t *h_init(int bytes, bool unsafe_stack, float gc_threshold) {
    
    heap_t *h;
    h = malloc(sizeof(heap_t));
    h->size = bytes;
    
    h->bucket[START_INDEX]  = calloc(1, size*2);
    h->bucket[MIDDLE_INDEX] = h->bucket[START_INDEX] + size;
    h->bucket[EMPTY_INDEX]  = h->bucket[MIDDLE_INDEX] + size;
    
    h->frontier = h->bucket[START_INDEX];
    
    h->alloc_map[START_INDEX] = calloc(1, size*2);
    return h;
}

void *h_alloc_struct(heap_t *h, char *dbg_value) {
    
}

void *h_alloc_raw(heap_t *h, int bytes) {
    
}


int main() {
    heap_t *hp = h_init(100, true, 0.5);
    //void* end = END(hp);
    //printf("end of heap is %p\n", end);
    printf("made heap\n");
}





