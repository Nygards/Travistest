#include "../src/stack.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdint.h>


void stack_setup_test(){
  int i;
  int x;
  stacks_t *stack = stack_setup(&i, &x);
  CU_ASSERT_TRUE(stack != NULL);
  free(stack);
}

void stack_traverse_test(){
  int a;
  int d;
  uintptr_t e = (uintptr_t) &a;
  stacks_t *stack = stack_setup(&a, &d);
  CU_ASSERT_TRUE(stack_traverse(stack) == NULL);
  CU_ASSERT_TRUE(stack_traverse(NULL) == NULL);
  stack_set_start(stack);
  CU_ASSERT_TRUE(stack != NULL);
  void* test = stack_traverse(stack);
  CU_ASSERT_TRUE(test != NULL);
  CU_ASSERT_TRUE(*(uintptr_t*)test == e);
  CU_ASSERT_TRUE(NULL == stack_traverse(stack));
  free(stack);
}

void stack_set_start_test() {
  int a;
  int b;
  stacks_t *stack = stack_setup(&a, &b);
  stack_set_start(stack);
  CU_ASSERT_TRUE(stack != NULL);
  free(stack);
}

