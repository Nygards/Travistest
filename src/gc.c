#include <stdio.h>
#include "gc.h"
///#include "heap.h"


struct heap {
    size_t anything;
    size_t everything;
};


heap_t *h_init(size_t bytes, bool unsafe_stack, float gc_threshold) {
    return calloc(1, bytes);
}


void h_delete(heap_t *h) {
    free(h);
}


void h_delete_dbg(heap_t *h, void *dbg_value) {
    free(h);
}


void *h_alloc_struct(heap_t *h, char *layout) {
    return NULL;
}


void *h_alloc_data(heap_t *h, size_t bytes) {
    return calloc(1, bytes);
}


size_t h_gc(heap_t *h) {
    return 0;
}


size_t h_gc_dbg(heap_t *h, bool unsafe_stack) {
    return 0;
}


size_t h_used(heap_t *h) {
    return 0;
}


size_t h_avail(heap_t *h){
    return 0;
}
