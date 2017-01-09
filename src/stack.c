#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdint.h>
#include <assert.h>
#include "stack.h"

typedef struct stacks stacks_t;

struct stacks{
  int max_heap;
  int min_heap;
  void* current;
  void* stack_finish;
  bool downward_growth;
};

stacks_t *stack_setup(void* heap_start, void* heap_end){
  stacks_t *stack = calloc(1, sizeof(stacks_t));
  extern char** environ;
  stack->stack_finish = environ;
  int y;
  int x;
  if (&y > &x) {
    stack->downward_growth = false;
  }
  else {
    stack->downward_growth = true;
  }
  //Gör om start & end till int's för att jämföra värdet 
  uintptr_t uintMin = (uintptr_t) heap_start;
  uintptr_t uintMax = (uintptr_t) heap_end;
  int intMin = uintMin;
  int intMax = uintMax;
  stack->min_heap = intMin;
  stack->max_heap = intMax;
  return stack;
}

void **stack_traverse(stacks_t *stack) {
  if (stack == NULL || stack->current == NULL) return NULL;
  while (stack->current != stack->stack_finish) {
    if (*(int*)stack->current >= stack->min_heap && *(int*)stack->current <= stack->max_heap){
      void **to_return = stack->current;
      if (stack->downward_growth){
        stack->current += 1;
      }
      else stack->current -= 1;
      return to_return;
    }
    else {
      if (stack->downward_growth){
        stack->current += 1;
      }
      else stack->current -= 1;
    }
  }
  return NULL;                           
}

void stack_set_start(stacks_t *stack){
  int i;
  stack->current = &i;
}
