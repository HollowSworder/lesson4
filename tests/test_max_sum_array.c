#include <stdlib.h>
#include <string.h>
#include "../extra/Unity/unity.h"
#include "../include/advanced_array_function.h"

void setUp(void) {}

void tearDown(void) {}

void test_max_subarray_sum_normal_case(void) {
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(nums) / sizeof(nums[0]);
    
    int result = max_subarray_sum(nums, size);
    TEST_ASSERT_EQUAL_INT(6, result);
}

void test_max_subarray_sum_all_positive(void) {
    int nums[] = {1, 2, 3, 4, 5};
    int size = sizeof(nums) / sizeof(nums[0]);
    
    int result = max_subarray_sum(nums, size);
    TEST_ASSERT_EQUAL_INT(15, result);
}

void test_max_subarray_sum_all_negative(void) {
    int nums[] = {-5, -2, -8, -1, -3};
    int size = sizeof(nums) / sizeof(nums[0]);
    
    int result = max_subarray_sum(nums, size);
    TEST_ASSERT_EQUAL_INT(-1, result); // Наименьшее по модулю отрицательное
}

void test_max_subarray_sum_single_element(void) {
    int nums[] = {5};
    int size = sizeof(nums) / sizeof(nums[0]);
    
    int result = max_subarray_sum(nums, size);
    TEST_ASSERT_EQUAL_INT(5, result);
}

void test_max_subarray_sum_empty_array(void) {
    int* nums = NULL;
    int size = 0;
    
    int result = max_subarray_sum(nums, size);
    TEST_ASSERT_EQUAL_INT(0, result);
}

void test_max_subarray_sum_alternating(void) {
    int nums[] = {2, -1, 3, -2, 4, -1, 5};
    int size = sizeof(nums) / sizeof(nums[0]);
    
    int result = max_subarray_sum(nums, size);
    TEST_ASSERT_EQUAL_INT(10, result); // 2 + (-1) + 3 + (-2) + 4 + (-1) + 5 = 10
}

void test_max_subarray_sum_max_at_beginning(void) {
    int nums[] = {10, 2, -5, 1, 3};
    int size = sizeof(nums) / sizeof(nums[0]);
    
    int result = max_subarray_sum(nums, size);
    TEST_ASSERT_EQUAL_INT(12, result); // 10 + 2 = 12
}

void test_max_subarray_sum_max_at_end(void) {
    int nums[] = {1, -2, 3, 4, 10};
    int size = sizeof(nums) / sizeof(nums[0]);
    
    int result = max_subarray_sum(nums, size);
    TEST_ASSERT_EQUAL_INT(17, result); // 3 + 4 + 10 = 17
}

void test_max_subarray_sum_single_zero(void) {
    int nums[] = {0};
    int size = sizeof(nums) / sizeof(nums[0]);
    
    int result = max_subarray_sum(nums, size);
    TEST_ASSERT_EQUAL_INT(0, result);
}

void test_max_subarray_sum_zeros_and_negatives(void) {
    int nums[] = {0, -1, 0, -2, 0};
    int size = sizeof(nums) / sizeof(nums[0]);
    
    int result = max_subarray_sum(nums, size);
    TEST_ASSERT_EQUAL_INT(0, result);
}

int main(void) {
    UNITY_BEGIN();
    
    RUN_TEST(test_max_subarray_sum_normal_case);
    RUN_TEST(test_max_subarray_sum_all_positive);
    RUN_TEST(test_max_subarray_sum_all_negative);
    RUN_TEST(test_max_subarray_sum_single_element);
    RUN_TEST(test_max_subarray_sum_empty_array);
    RUN_TEST(test_max_subarray_sum_alternating);
    RUN_TEST(test_max_subarray_sum_max_at_beginning);
    RUN_TEST(test_max_subarray_sum_max_at_end);
    RUN_TEST(test_max_subarray_sum_single_zero);
    RUN_TEST(test_max_subarray_sum_zeros_and_negatives);
    
    return UNITY_END();
}
