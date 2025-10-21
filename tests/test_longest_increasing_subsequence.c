#include <stdlib.h>
#include <string.h>
#include "../extra/Unity/unity.h"
#include "../include/advanced_array_function.h"

void setUp(void) {}

void tearDown(void) {}

// Тест 1: Базовый случай из классического примера
void test_lis_basic_case(void) {
    int nums[] = {10, 9, 2, 3, 7, 101, 18};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int expected = 4; // [2, 3, 7, 101]
    
    int result_default = length_of_lis(nums, numsSize);
    
    TEST_ASSERT_EQUAL_INT(expected, result_default);
}

// Тест 2: Уже отсортированный массив
void test_lis_sorted_array(void) {
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int expected = 8;
    
    int result_default = length_of_lis(nums, numsSize);
    
    TEST_ASSERT_EQUAL_INT(expected, result_default);
}

// Тест 3: Обратно отсортированный массив
void test_lis_reverse_sorted(void) {
    int nums[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int expected = 1; // Любой один элемент
    
    int result_default = length_of_lis(nums, numsSize);
    
    TEST_ASSERT_EQUAL_INT(expected, result_default);
}

// Тест 4: Все элементы одинаковые
void test_lis_all_equal(void) {
    int nums[] = {5, 5, 5, 5, 5, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int expected = 1; // Только один элемент в подпоследовательности
    
    int result_default = length_of_lis(nums, numsSize);
    
    TEST_ASSERT_EQUAL_INT(expected, result_default);
}

// Тест 5: Один элемент
void test_lis_single_element(void) {
    int nums[] = {42};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int expected = 1;
    
    int result_default = length_of_lis(nums, numsSize);
    
    TEST_ASSERT_EQUAL_INT(expected, result_default);
}

// Тест 6: Пустой массив
void test_lis_empty_array(void) {
    int* nums = NULL;
    int numsSize = 0;
    int expected = 0;
    
    int result_default = length_of_lis(nums, numsSize);
    
    TEST_ASSERT_EQUAL_INT(expected, result_default);
}


// Тест 8: Отрицательные числа
void test_lis_negative_numbers(void) {
    int nums[] = {-5, -3, -2, -1, -4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int expected = 4; // [-5, -3, -2, -1]
    
    int result_default = length_of_lis(nums, numsSize);
    
    TEST_ASSERT_EQUAL_INT(expected, result_default);
}

// Тест 9: Смешанные положительные и отрицательные числа
void test_lis_mixed_numbers(void) {
    int nums[] = {-2, 1, -1, 2, 3, -3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int expected = 3;
    
    int result_default = length_of_lis(nums, numsSize);
    
    TEST_ASSERT_EQUAL_INT(expected, result_default);
}

// Тест 10: Большие числа
void test_lis_large_numbers(void) {
    int nums[] = {1000000, 1000001, 1000002, 1000000};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int expected = 3; // [1000000, 1000001, 1000002]
    
    int result_default = length_of_lis(nums, numsSize);
    
    TEST_ASSERT_EQUAL_INT(expected, result_default);
}

// Тест 11: Строго возрастающая с пропусками
void test_lis_strictly_increasing_with_gaps(void) {
    int nums[] = {1, 5, 10, 15, 20, 25};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int expected = 6;
    
    int result_default = length_of_lis(nums, numsSize);
    
    TEST_ASSERT_EQUAL_INT(expected, result_default);
}


int main(void) {
    UNITY_BEGIN();
    
    RUN_TEST(test_lis_basic_case);
    RUN_TEST(test_lis_sorted_array);
    RUN_TEST(test_lis_reverse_sorted);
    RUN_TEST(test_lis_all_equal);
    RUN_TEST(test_lis_single_element);
    RUN_TEST(test_lis_empty_array);
    RUN_TEST(test_lis_negative_numbers);
    RUN_TEST(test_lis_mixed_numbers);
    RUN_TEST(test_lis_large_numbers);
    RUN_TEST(test_lis_strictly_increasing_with_gaps);
    
    return UNITY_END();
}
