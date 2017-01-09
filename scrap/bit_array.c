#include "bit_array.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include <stdint.h>

#define BITS_IN_BYTES 8

int8_t *new_bit_array(int bit_size) {
  int8_t *bit_a;
  bit_a = calloc(1 , bit_size/8 + 1);

  return bit_a;
}

void bit_array_set_one(int8_t *bit_a, int index) {
    int byte_index = index/BITS_IN_BYTES;
    int bit_offset = index % BITS_IN_BYTES;

    int8_t byte_operator = 1;
    byte_operator = byte_operator << bit_offset;

    bit_a[byte_index] |= byte_operator;
}


void bit_array_set_zero(int8_t *bit_a, int index) {
  int byte_index = index/BITS_IN_BYTES;
  int bit_offset = index % BITS_IN_BYTES;

  int8_t byte_operator = 1;

  byte_operator = byte_operator << bit_offset;

  byte_operator = ~byte_operator;

  bit_a[byte_index] &= byte_operator;
}


bool bit_array_get(int8_t *bit_a, int index){
  int byte_index = index/BITS_IN_BYTES;
  int bit_offset = index % BITS_IN_BYTES;

  int8_t result;
  int8_t byte_operator = 1;

  byte_operator = byte_operator << bit_offset;
  result = bit_a[byte_index] & byte_operator;

  return result;
}


//TODO: proper tests
int main(){
  //int8_t a[3];
  int8_t *a = new_bit_array(24);
  printf("a is %d\n", *a);
  bit_array_set_one(2,a);
  printf("a is %d\n", *a);

  printf("-------------------\n");

  printf("a is %d\n", *a);
  bit_array_set_one(0,a);
  printf("a is %d\n", *a);

  printf("-------------------\n");

  printf("a is %d\n", *a);
  bit_array_set_zero(2,a);
  printf("a is %d\n", *a);

  printf("-------------------\n");

  int8_t *b = new_bit_array(24);
  printf("b is %d\n", *b);
  bit_array_set_one(10,b);
  printf("b is %d\n", *b);

  printf("-------------------\n");

  int8_t *c = new_bit_array(24);
  printf("c is %d\n", *c);
  bit_array_set_one(2,c);
  printf("c is %d\n", *c);

  printf("-------------------\n");

  printf("c is %d\n", *c);
  bit_array_set_one(8,c);
  printf("c is %d\n", *c);

  printf("-------------------\n");


  printf("c is %d\n", *c);
  bit_array_set_one(11,c);
  printf("c is %d\n", *c);

  printf("-------------------\n");

  printf("c is %d\n", *c);
  bool a_get1 = bit_array_get(4,c);
  printf("c is %d\n", a_get1);

  printf("-------------------\n");

  printf("c is %d\n", *c);
  bool a_get2 = bit_array_get(8,c);
  printf("c is %d\n", a_get2);

  printf("-------------------\n");

  printf("c is %d\n", *c);
  bool a_get3 = bit_array_get(11,c);
  printf("c is %d\n", a_get3);

  printf("-------------------\n");

  printf("c is %d\n", *c);
  bool a_get4 = bit_array_get(12,c);
  printf("c is %d\n", a_get4);
}
