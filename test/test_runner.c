#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "header_test.h"
#include "stack_test.h"

int main()
{
  CU_initialize_registry();

  CU_pSuite header_test = CU_add_suite("Tests header functions", NULL, NULL);
  CU_add_test(header_test, "is_format_string", test_is_format_string);
  CU_add_test(header_test, "set_format", test_set_format);
  CU_add_test(header_test, "get_format", test_get_format);
  CU_add_test(header_test, "if_forward", test_if_forward);
  CU_add_test(header_test, "set_forward", test_set_forward);
  CU_add_test(header_test, "get_forward", test_get_forward);
  CU_add_test(header_test, "is_data", test_is_data);
  CU_add_test(header_test, "set_data", test_set_data);
  CU_add_test(header_test, "get_data_size", test_get_data_size);
  
  
  CU_pSuite stack_test = CU_add_suite("Tests stack functions", NULL, NULL);
  CU_add_test(stack_test, "stack_setup_test", stack_setup_test);
  CU_add_test(stack_test, "stack_traverse_test", stack_traverse_test);
  CU_add_test(stack_test, "stack_set_start_test", stack_set_start_test);
  
  CU_basic_run_tests();

  CU_cleanup_registry();
  
  return 0;
}
