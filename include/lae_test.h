/*
 *  lae_test.h
 *  lae
 *
 *  Created by Kyle C Weicht on 6/5/12.
 *  Copyright (c) 2012 Kyle C Weicht. All rights reserved.
 */
#ifndef __lae_lae_test_h_
#define __lae_lae_test_h_

/*----------------------------------------------------------------------------*/
/* C headers */
#include <stdint.h>
#include <string.h>
/* C++ headers */
/* External headers */
/* Internal headers */
/*----------------------------------------------------------------------------*/

#ifdef __cplusplus

/**
 * Test macros and functions
 */
#define TEST(test_name)                                                     \
    static void TEST_##test_name(void);                                     \
    static int _##test_name##_register = register_test(&TEST_##test_name);  \
    static void TEST_##test_name(void)
#define IGNORE_TEST(test_name)                                              \
    static void TEST_##test_name(void);                                     \
    static int _##test_name##_register = ignore_test(&TEST_##test_name);    \
    static void TEST_##test_name(void)
    
typedef void (test_func_t)(void);
int register_test(test_func_t* test);
int ignore_test(test_func_t* test);

/**
 * Checking functions
 */
#define FAIL(message)   \
    fail(__FILE__, __LINE__, message)
void fail(const char* file, int line, const char* message);

/* bool */
#define CHECK_TRUE(value) \
    check_true(__FILE__, __LINE__, (int)(value))
#define CHECK_FALSE(value) \
    check_false(__FILE__, __LINE__, (int)(value))

void check_true(const char* file, int line, int value);
void check_false(const char* file, int line, int value);

/* integer */
#define CHECK_EQUAL(expected, actual) \
    check_equal(__FILE__, __LINE__, (int64_t)expected, (int64_t)actual)
#define CHECK_NOT_EQUAL(expected, actual) \
    check_not_equal(__FILE__, __LINE__, (int64_t)expected, (int64_t)actual)
#define CHECK_LESS_THAN(left, right) \
    check_less_than(__FILE__, __LINE__, (int64_t)left, (int64_t)right)
#define CHECK_GREATER_THAN(left, right) \
    check_greater_than(__FILE__, __LINE__, (int64_t)left, (int64_t)right)
#define CHECK_LESS_THAN_EQUAL(left, right) \
    check_less_than_equal(__FILE__, __LINE__, (int64_t)left, (int64_t)right)
#define CHECK_GREATER_THAN_EQUAL(left, right) \
    check_greater_than_equal(__FILE__, __LINE__, (int64_t)left, (int64_t)right)
    
void check_equal(const char* file, int line, int64_t expected, int64_t actual);
void check_not_equal(const char* file, int line, int64_t expected, int64_t actual);
void check_less_than(const char* file, int line, int64_t left, int64_t right);
void check_greater_than(const char* file, int line, int64_t left, int64_t right);
void check_less_than_equal(const char* file, int line, int64_t left, int64_t right);
void check_greater_than_equal(const char* file, int line, int64_t left, int64_t right);
    
/* pointer */
#define CHECK_POINTER_EQUAL(expected, actual) \
    check_pointer_equal(__FILE__, __LINE__, (const void*)expected, (const void*)actual)
#define CHECK_POINTER_NOT_EQUAL(expected, actual) \
    check_pointer_not_equal(__FILE__, __LINE__, (const void*)expected, (const void*)actual)
#define CHECK_POINTER_NULL(ptr) \
    check_pointer_null(__FILE__, __LINE__, (const void*)ptr)
#define CHECK_POINTER_NOT_NULL(ptr) \
    check_pointer_not_null(__FILE__, __LINE__, (const void*)ptr)
    
void check_pointer_equal(const char* file, int line, const void* expected, const void* actual);
void check_pointer_not_equal(const char* file, int line, const void* expected, const void* actual);
void check_pointer_null(const char* file, int line, const void* pointer);
void check_pointer_not_null(const char* file, int line, const void* pointer);

/* float */
#define CHECK_EQUAL_FLOAT(expected, actual) \
    check_equal_float(__FILE__, __LINE__, (double)expected, (double)actual)
#define CHECK_NOT_EQUAL_FLOAT(expected, actual) \
    check_not_equal_float(__FILE__, __LINE__, (double)expected, (double)actual)
#define CHECK_LESS_THAN_FLOAT(left, right) \
    check_less_than_float(__FILE__, __LINE__, (double)left, (double)right)
#define CHECK_GREATER_THAN_FLOAT(left, right) \
    check_greater_than_float(__FILE__, __LINE__, (double)left, (double)right)
#define CHECK_LESS_THAN_EQUAL_FLOAT(left, right) \
    check_less_than_equal_float(__FILE__, __LINE__, (double)left, (double)right)
#define CHECK_GREATER_THAN_EQUAL_FLOAT(left, right) \
    check_greater_than_equal_float(__FILE__, __LINE__, (double)left, (double)right)
    
void check_equal_float(const char* file, int line, double expected, double actual);
void check_not_equal_float(const char* file, int line, double expected, double actual);
void check_less_than_float(const char* file, int line, double left, double right);
void check_greater_than_float(const char* file, int line, double left, double right);
void check_less_than_equal_float(const char* file, int line, double left, double right);
void check_greater_than_equal_float(const char* file, int line, double left, double right);

/* string */
#define CHECK_EQUAL_STRING(expected, actual) \
    check_equal_string(__FILE__, __LINE__, expected, actual)
#define CHECK_NOT_EQUAL_STRING(expected, actual) \
    check_not_equal_string(__FILE__, __LINE__, expected, actual)
    
void check_equal_string(const char* file, int line, const char* expected, const char* actual);
void check_not_equal_string(const char* file, int line, const char* expected, const char* actual);


extern "C" { // Use C linkage
#endif 

/**
 * Runs all registered tests and returns the number of failures
 */
int run_all_tests(int argc, const char* argv[]);

#ifdef __cplusplus
}
#endif

#endif /* include guard */
