#ifndef __heap_h__
#define __heap_h__
#include <stddef.h>
#include <stdbool.h>



struct heap {
    int size;
    void *bucket[3];
    void *frontier;
    bool *alloc_map[2];
};

typedef struct heap heap_t;

/// Initiate heap
/// \param bytes - Size of byte
/// \param
/// \param 
/// \returns a heap
heap_t *h_init(int bytes, bool unsafe_stack, float gc_threshold);




/// 
/// \param
/// \param
/// \returns 
void *h_alloc_struct(heap_t *h, char *dbg_value);




/// Alloc memory fith no pointer only raw data
/// \param
/// \param
/// \returns 
void *h_alloc_raw(heap_t *h, int bytes);

#endif
