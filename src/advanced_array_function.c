#include "../include/advanced_array_function.h"
#include <stdlib.h>
#include <stddef.h>

int max_subarray_sum(int* nums, int size) {
    if (size == 0) return 0;
    
    int maxSum = nums[0];
    int current_sum = nums[0];
    
    for (int i = 1; i < size; i++) {
        if (current_sum < 0) {
            current_sum = nums[i];
        } else {
            current_sum += nums[i];
        }
        
        if (current_sum > maxSum) {
            maxSum = current_sum;
        }
    }
    
    return maxSum;
}

int length_of_lis(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    
    int max_len = 1;
    int current_len = 1;
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i-1]) {
            current_len++;
            if (current_len > max_len) {
                max_len = current_len;
            }
        } else {
            current_len = 1; 
        }
    }
    
    return max_len;
}

int* merge(int* intervals, int intervalsSize, int* returnSize) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    for (int i = 0; i < intervalsSize - 1; i++) {
        for (int j = 0; j < intervalsSize - i - 1; j++) {
            if (intervals[2*j] > intervals[2*(j+1)]) {
                int temp = intervals[2*j];
                intervals[2*j] = intervals[2*(j+1)];
                intervals[2*(j+1)] = temp;
                
                temp = intervals[2*j + 1];
                intervals[2*j + 1] = intervals[2*(j+1) + 1];
                intervals[2*(j+1) + 1] = temp;
            }
        }
    }
    
    int* result = (int*)malloc(2 * intervalsSize * sizeof(int));
    *returnSize = 0;
    
    int start = intervals[0];
    int end = intervals[1];
    
    for (int i = 1; i < intervalsSize; i++) {
        int current_start = intervals[2*i];
        int current_end = intervals[2*i + 1];
        
        if (current_start <= end) {

            if (current_end > end) {
                end = current_end;
            }
        } else {

            result[*returnSize * 2] = start;
            result[*returnSize * 2 + 1] = end;
            (*returnSize)++;
            
            start = current_start;
            end = current_end;
        }
    }
    
    result[*returnSize * 2] = start;
    result[*returnSize * 2 + 1] = end;
    (*returnSize)++;
    
    return result;
}