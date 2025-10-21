#include <stdlib.h>
#include <string.h>
#include "../extra/Unity/unity.h"
#include "../include/advanced_array_function.h"

void setUp(void) {}

void tearDown(void) {}


// Вспомогательная функция для сравнения массивов интервалов
void assert_intervals_equal(int* expected, int expected_size, int* actual, int actual_size, int line) {
    char message[100];
    
    if (expected_size != actual_size) {
        sprintf(message, "Line %d: Expected size %d, got %d", line, expected_size, actual_size);
        TEST_FAIL_MESSAGE(message);
        return;
    }
    
    for (int i = 0; i < 2 * expected_size; i++) {
        if (expected[i] != actual[i]) {
            sprintf(message, "Line %d: At index %d, expected %d, got %d", line, i, expected[i], actual[i]);
            TEST_FAIL_MESSAGE(message);
            return;
        }
    }
}

#define ASSERT_INTERVALS_EQUAL(exp, exp_size, act, act_size) \
    assert_intervals_equal(exp, exp_size, act, act_size, __LINE__)

// Тест 1: Базовый случай из условия
void test_merge_basic_case(void) {
    int intervals[] = {1, 3, 2, 6, 8, 10, 15, 18};
    int expected[] = {1, 6, 8, 10, 15, 18};
    int intervals_size = 4;
    int expected_size = 3;
    int return_size;
    
    int* result = merge(intervals, intervals_size, &return_size);
    
    ASSERT_INTERVALS_EQUAL(expected, expected_size, result, return_size);
    free(result);
}

// Тест 2: Полное перекрытие интервалов
void test_merge_complete_overlap(void) {
    int intervals[] = {1, 4, 2, 3};
    int expected[] = {1, 4};
    int intervals_size = 2;
    int expected_size = 1;
    int return_size;
    
    int* result = merge(intervals, intervals_size, &return_size);
    
    ASSERT_INTERVALS_EQUAL(expected, expected_size, result, return_size);
    free(result);
}

// Тест 3: Все интервалы сливаются в один
void test_merge_all_into_one(void) {
    int intervals[] = {1, 3, 2, 6, 8, 10, 15, 18, 16, 20, 0, 25};
    int expected[] = {0, 25};
    int intervals_size = 6;
    int expected_size = 1;
    int return_size;
    
    int* result = merge(intervals, intervals_size, &return_size);
    
    ASSERT_INTERVALS_EQUAL(expected, expected_size, result, return_size);
    free(result);
}

// Тест 4: Нет пересечений
void test_merge_no_overlaps(void) {
    int intervals[] = {1, 2, 3, 4, 5, 6};
    int expected[] = {1, 2, 3, 4, 5, 6};
    int intervals_size = 3;
    int expected_size = 3;
    int return_size;
    
    int* result = merge(intervals, intervals_size, &return_size);
    
    ASSERT_INTERVALS_EQUAL(expected, expected_size, result, return_size);
    free(result);
}

// Тест 5: Один интервал
void test_merge_single_interval(void) {
    int intervals[] = {5, 10};
    int expected[] = {5, 10};
    int intervals_size = 1;
    int expected_size = 1;
    int return_size;
    
    int* result = merge(intervals, intervals_size, &return_size);
    
    ASSERT_INTERVALS_EQUAL(expected, expected_size, result, return_size);
    free(result);
}

// Тест 6: Пустой массив
void test_merge_empty_array(void) {
    int* intervals = NULL;
    int intervals_size = 0;
    int expected_size = 0;
    int return_size;
    
    int* result = merge(intervals, intervals_size, &return_size);
    
    TEST_ASSERT_NULL(result);
    TEST_ASSERT_EQUAL_INT(expected_size, return_size);
}

// Тест 7: Интервалы в обратном порядке
void test_merge_reverse_order(void) {
    int intervals[] = {15, 18, 8, 10, 2, 6, 1, 3};
    int expected[] = {1, 6, 8, 10, 15, 18};
    int intervals_size = 4;
    int expected_size = 3;
    int return_size;
    
    int* result = merge(intervals, intervals_size, &return_size);
    
    ASSERT_INTERVALS_EQUAL(expected, expected_size, result, return_size);
    free(result);
}

// Тест 8: Касание интервалов
void test_merge_touching_intervals(void) {
    int intervals[] = {1, 5, 5, 10, 10, 15};
    int expected[] = {1, 15};
    int intervals_size = 3;
    int expected_size = 1;
    int return_size;
    
    int* result = merge(intervals, intervals_size, &return_size);
    
    ASSERT_INTERVALS_EQUAL(expected, expected_size, result, return_size);
    free(result);
}

// Тест 9: Отрицательные числа
void test_merge_negative_numbers(void) {
    int intervals[] = {-5, -1, -3, 2, 0, 4, 3, 5};
    int expected[] = {-5, 5};
    int intervals_size = 4;
    int expected_size = 1;
    int return_size;
    
    int* result = merge(intervals, intervals_size, &return_size);
    
    ASSERT_INTERVALS_EQUAL(expected, expected_size, result, return_size);
    free(result);
}

// Тест 10: Большие числа
void test_merge_large_numbers(void) {
    int intervals[] = {1000000, 2000000, 1500000, 2500000, 3000000, 4000000};
    int expected[] = {1000000, 2500000, 3000000, 4000000};
    int intervals_size = 3;
    int expected_size = 2;
    int return_size;
    
    int* result = merge(intervals, intervals_size, &return_size);
    
    ASSERT_INTERVALS_EQUAL(expected, expected_size, result, return_size);
    free(result);
}

// Тест 11: Одинаковые интервалы
void test_merge_duplicate_intervals(void) {
    int intervals[] = {1, 3, 1, 3, 1, 3};
    int expected[] = {1, 3};
    int intervals_size = 3;
    int expected_size = 1;
    int return_size;
    
    int* result = merge(intervals, intervals_size, &return_size);
    
    ASSERT_INTERVALS_EQUAL(expected, expected_size, result, return_size);
    free(result);
}

// Тест 12: Цепочка пересечений
void test_merge_chain_overlap(void) {
    int intervals[] = {1, 10, 5, 15, 12, 20, 18, 25};
    int expected[] = {1, 25};
    int intervals_size = 4;
    int expected_size = 1;
    int return_size;
    
    int* result = merge(intervals, intervals_size, &return_size);
    
    ASSERT_INTERVALS_EQUAL(expected, expected_size, result, return_size);
    free(result);
}

// Тест 13: Частичное слияние
void test_merge_partial_merge(void) {
    int intervals[] = {1, 5, 3, 7, 6, 10, 12, 15};
    int expected[] = {1, 10, 12, 15};
    int intervals_size = 4;
    int expected_size = 2;
    int return_size;
    
    int* result = merge(intervals, intervals_size, &return_size);
    
    ASSERT_INTERVALS_EQUAL(expected, expected_size, result, return_size);
    free(result);
}

// Тест 14: Интервалы с нулевой длиной
void test_merge_zero_length(void) {
    int intervals[] = {1, 1, 2, 2, 3, 3};
    int expected[] = {1, 1, 2, 2, 3, 3};
    int intervals_size = 3;
    int expected_size = 3;
    int return_size;
    
    int* result = merge(intervals, intervals_size, &return_size);
    
    ASSERT_INTERVALS_EQUAL(expected, expected_size, result, return_size);
    free(result);
}

// Тест 15: Сложный случай с вложенными интервалами
void test_merge_complex_nested(void) {
    int intervals[] = {1, 10, 2, 5, 3, 4, 6, 8, 12, 15, 13, 14};
    int expected[] = {1, 10, 12, 15};
    int intervals_size = 6;
    int expected_size = 2;
    int return_size;
    
    int* result = merge(intervals, intervals_size, &return_size);
    
    ASSERT_INTERVALS_EQUAL(expected, expected_size, result, return_size);
    free(result);
}

// Тест 16: Только один интервал с большим перекрытием
void test_merge_single_large_overlap(void) {
    int intervals[] = {1, 10, 2, 9, 3, 8, 4, 7};
    int expected[] = {1, 10};
    int intervals_size = 4;
    int expected_size = 1;
    int return_size;
    
    int* result = merge(intervals, intervals_size, &return_size);
    
    ASSERT_INTERVALS_EQUAL(expected, expected_size, result, return_size);
    free(result);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_merge_basic_case);
    RUN_TEST(test_merge_complete_overlap);
    RUN_TEST(test_merge_all_into_one);
    RUN_TEST(test_merge_no_overlaps);
    RUN_TEST(test_merge_single_interval);
    RUN_TEST(test_merge_empty_array);
    RUN_TEST(test_merge_reverse_order);
    RUN_TEST(test_merge_touching_intervals);
    RUN_TEST(test_merge_negative_numbers);
    RUN_TEST(test_merge_large_numbers);
    RUN_TEST(test_merge_duplicate_intervals);
    RUN_TEST(test_merge_chain_overlap);
    RUN_TEST(test_merge_partial_merge);
    RUN_TEST(test_merge_zero_length);
    RUN_TEST(test_merge_complex_nested);
    RUN_TEST(test_merge_single_large_overlap);
    
    return UNITY_END();
}
