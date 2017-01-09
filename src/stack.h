#ifndef __stack_h__
#define __stack_h__
#include <stdbool.h>


/// The data type holding info of memory segment

typedef struct stacks stacks_t;

/// Initiate the stacks struct
/// \param heap_start the adress of the start of the heap
/// \param heap_end the adress of the end of the heap
/// \returns a pointer to the created stack

stacks_t* stack_setup(void* heap_start, void* heap_end);


/// Traverses the stack looking for int's that's between the start and end value from stack_start. IMPORTANT: use stack_set_top before to set the top of the stack. 
/// \param stack the stack to traverse
/// \returns the pointer to the stack or returns NULL if you hit the bottom of the stack, the stack is null or you didnt use stack_set_top.

void** stack_traverse(stacks_t *stack);


/// Sets the top of the stack
/// \param stack the stack to set the top to
/// \returns

void stack_set_start(stacks_t *stack);

#endif

