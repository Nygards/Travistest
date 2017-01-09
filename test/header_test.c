#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <CUnit/CUnit.h>
#include "../src/header.h"
#include <CUnit/Basic.h>


void test_is_format_string() {
    heap_t* h = calloc(1, sizeof(int));
    header* head = calloc(1,sizeof(head));
    char* str = "ii**cd";
    header_set_format_string(h, head, str);
    CU_ASSERT_TRUE(header_is_format_string(head));
    int i;
    header_set_forward(head, &i);
    CU_ASSERT_FALSE(header_is_format_string(head));
    header_set_data(head, sizeof(int));
    CU_ASSERT_FALSE(header_is_format_string(head));
    
    free(h);
    free(head);
}


void test_set_format() {
    heap_t* h = calloc(1, sizeof(int));
    header* head = calloc(1,sizeof(head));

    //*head = (intptr_t) 0;

    char* str = "ii**cd";
    header_set_format_string(h, head, str);

    //CU_ASSERT_PTR_NOT_NULL(*head);

    char* comp = header_get_format_string(head);

    CU_ASSERT_STRING_EQUAL(str, comp);

    free(h);
    free(head);
}

void test_get_format() {
    heap_t* h = calloc(1, sizeof(int));
    header* head = calloc(1,sizeof(head));
    char* str = "ii**cd";
    header_set_format_string(h, head, str);
    CU_ASSERT_STRING_EQUAL(str, header_get_format_string(head));

    int i;
    header_set_forward(head, &i);
    CU_ASSERT_PTR_NULL(header_get_format_string(head));

    header_set_format_string(h, head, str);
    CU_ASSERT_PTR_NOT_NULL(header_get_format_string(head));

    header_set_data(head, sizeof(int));
    CU_ASSERT_PTR_NULL(header_get_format_string(head));

    free(h);
    free(head);
}

void test_if_forward() {
    heap_t* h = calloc(1, sizeof(int));
    header* head = calloc(1,sizeof(head));
    char* str = "ii**cd";
    header_set_format_string(h, head, str);
    CU_ASSERT_FALSE(header_is_forward(head));
    int i;
    header_set_forward(head, &i);
    CU_ASSERT_TRUE(header_is_forward(head));
    CU_ASSERT_FALSE(header_is_data(head));

    free(h);
    free(head);
}

void test_set_forward() {
    heap_t* h = calloc(1, sizeof(int));
    header* head = calloc(1, sizeof(head));
    char* str = "ii**cd";
    header_set_format_string(h, head, str);
    CU_ASSERT_FALSE(header_is_forward(head));
    int i;
    header_set_forward(head, &i);
    CU_ASSERT_TRUE(header_is_forward(head));
    CU_ASSERT_PTR_EQUAL(&i, header_get_forward(head));

    free(h);
    free(head);
}

void test_get_forward() {
    heap_t* h = calloc(1, sizeof(int));
    header* head = calloc(1, sizeof(head));
    char* str = "ii**cd";
    header_set_format_string(h, head, str);
    CU_ASSERT_PTR_NULL(header_get_forward(head));
    int i;
    header_set_forward(head, &i);
    CU_ASSERT_TRUE(header_is_forward(head));
    CU_ASSERT_PTR_EQUAL(&i, header_get_forward(head));
    CU_ASSERT_FALSE(header_is_data(head));
    
    free(h);
    free(head);
}

void test_is_data() {
    heap_t* h = calloc(1, sizeof(int));
    header* head = calloc(1, sizeof(head));
    char* str = "ii**cd";
    header_set_format_string(h, head, str);
    CU_ASSERT_FALSE(header_is_data(head));
    header_set_data(head, sizeof(int));
    CU_ASSERT_TRUE(header_is_data(head));
    CU_ASSERT_FALSE(header_is_forward(head));
    
    free(h);
    free(head);
}

void test_set_data() {
    heap_t* h = calloc(1, sizeof(int));
    header* head = calloc(1, sizeof(head));
    char* str = "ii**cd";
    header_set_format_string(h, head, str);
    CU_ASSERT_FALSE(header_is_data(head));
    header_set_data(head, sizeof(int));
    CU_ASSERT_TRUE(header_is_data(head));
    CU_ASSERT_FALSE(header_is_forward(head));
    CU_ASSERT_EQUAL(sizeof(int),header_get_allocated_size(head));

    free(h);
    free(head);
}

void test_get_data_size() {
    heap_t* h = calloc(1, sizeof(int));
    header* head = calloc(1, sizeof(head));
    char* str = "ii**cd";
    header_set_format_string(h, head, str);
    CU_ASSERT_FALSE(header_is_data(head));
    header_set_data(head, sizeof(int));
    CU_ASSERT_TRUE(header_is_data(head));
    CU_ASSERT_EQUAL(sizeof(int),header_get_allocated_size(head));
    
    free(h);
    free(head);
}


