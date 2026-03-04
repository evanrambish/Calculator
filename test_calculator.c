#include "unity.h"
#include "calculator.h"
#include <limits.h>
// Optional but needs to be defined(runs BEFORE each test)
void setUp(void) {
// Initialize any resources needed for your tests here
// For example, you might reset a global value, dynamically allocate memory, etc.
// In this example, we do not need anything here.
}
// Optional but needs to be defined(runs AFTER each test)
void tearDown(void) {
// Clean up resources after each test
// For example, free dynamically allocated memory, reset global values, etc.
// In this example, we do not need anything here.
}
void test_add_positive_numbers(void) {
    TEST_ASSERT_EQUAL(5, add(2, 3)); // We expect 2 + 3 to be 5
}
void test_add_positive_and_negative_numbers(void) {
    TEST_ASSERT_EQUAL(1, add(5, -4));
}

void test_add_negative_numbers(void) {
    TEST_ASSERT_EQUAL(-7, add(-3, -4));
}

void test_add_zero(void) {
    TEST_ASSERT_EQUAL(10, add(10, 0));
    TEST_ASSERT_EQUAL(0, add(0, 0));
}
void test_add_overflow(void) {
    int result = add(INT_MAX, 1);
    TEST_ASSERT_TRUE(result < 0);
}
void test_add_underflow(void) {
    int result = add(INT_MIN, -1);
    TEST_ASSERT_TRUE(result > 0);
}
void test_subtract_basic(void) {
    TEST_ASSERT_EQUAL(2, subtract(5, 3));
}
void test_subtract_negative_result(void) {
    TEST_ASSERT_EQUAL(-2, subtract(3, 5));
}
void test_subtract_negative(void) {
    TEST_ASSERT_EQUAL(9, subtract(5, -4));
}
void test_subtract_both_negative(void) {
    TEST_ASSERT_EQUAL(1, subtract(-3, -4));
}
void test_subtract_zero(void) {
    TEST_ASSERT_EQUAL(10, subtract(10, 0));
    TEST_ASSERT_EQUAL(-10, subtract(0, 10));
}
void test_subtract_same_numbers(void) {
    TEST_ASSERT_EQUAL(0, subtract(7, 7));
    TEST_ASSERT_EQUAL(0, subtract(-7, -7));
}
void test_subtract_overflow(void) {
    int result = subtract(INT_MAX, -1);
    TEST_ASSERT_TRUE(result < 0);
}
void test_subtract_underflow(void) {
    int result = subtract(INT_MIN, 1); 
    TEST_ASSERT_TRUE(result > 0);
}
void test_multiply_basic(void) {
    TEST_ASSERT_EQUAL(15, multiply(5, 3));
}
void test_multiply_by_zero(void) {
    TEST_ASSERT_EQUAL(0, multiply(10, 0));
    TEST_ASSERT_EQUAL(0, multiply(0, 10));
}
void test_multiply_negative(void) {
    TEST_ASSERT_EQUAL(-12, multiply(3, -4));
}
int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_add_positive_numbers);
    RUN_TEST(test_add_positive_and_negative_numbers);
    RUN_TEST(test_add_negative_numbers);
    RUN_TEST(test_add_zero);
    RUN_TEST(test_add_overflow);
    RUN_TEST(test_add_underflow);
    RUN_TEST(test_subtract_basic);
    RUN_TEST(test_subtract_negative_result);
    RUN_TEST(test_subtract_negative);
    RUN_TEST(test_subtract_both_negative);
    RUN_TEST(test_subtract_zero);
    RUN_TEST(test_subtract_same_numbers);
    RUN_TEST(test_subtract_overflow);
    RUN_TEST(test_subtract_underflow);
    RUN_TEST(test_multiply_basic);
    RUN_TEST(test_multiply_by_zero);
    RUN_TEST(test_multiply_negative);

    return UNITY_END();
}