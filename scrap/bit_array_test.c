#include "bit_array.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

void new_bit_array_test(){
  //TODO: fix later the '10'
  int8_t *bit_array = new_bit_array(24);
  //Probably not correct
  CU_ASSERT_TRUE(bit_array != NULL);
}

void bit_array_set_one_test(){
  int8_t *a = new_bit_array(24);
  bit_array_set_one(a,2);
  bool a_get1 = bit_array_get(a,2);

  CU_ASSERT_TRUE(a_get1 == 1);
  CU_ASSERT_FALSE(a_get1 == 0);
}

void bit_array_set_zero_test(){
  int8_t *b = new_bit_array(24);
  bit_array_set_one(b,2);
  bit_array_set_zero(b,2);
  bool a_get2 = bit_array_get(b,2);

  CU_ASSERT_TRUE(a_get2 == 0);
  CU_ASSERT_FALSE(a_get2 == 1);
}

void bit_array_get_test(){
  int8_t *d = new_bit_array(24);
  bit_array_set_one(d,2);
  bool a_get3 = bit_array_get(d,2);
  CU_ASSERT_TRUE(a_get3 == 1);

  bit_array_set_zero(d,2);
  a_get3 = bit_array_get(d,2);
  CU_ASSERT_TRUE(a_get3 == 0);
}

int main(){
  CU_initialize_registry();

  CU_pSuite bitArraySuite = CU_add_suite("Bit Array tests", 0, 0);

  CU_add_test(bitArraySuite, "New Bit array", new_bit_array_test);
  CU_add_test(bitArraySuite, "Bit array set one", bit_array_set_one_test);
  CU_add_test(bitArraySuite, "Bit array set zero", bit_array_set_zero_test);
  CU_add_test(bitArraySuite, "Bit array get", bit_array_get_test);

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();

  return 0;
}
