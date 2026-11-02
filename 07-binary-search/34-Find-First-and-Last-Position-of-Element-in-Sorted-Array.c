#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* output = (int*)malloc(sizeof(int) * 2);

    if (output == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // left
    int left = 0;
    int right = numsSize - 1;
    int first_idx = -1;

    while (left <= right){
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target){
            first_idx = mid;
            right = mid - 1;
        }
        else if (nums[mid] < target){
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }

    }
    // right
    left = 0;
    right = numsSize - 1;
    int last_idx = -1;

    while (left <= right){
        int mid = left + (right - left) / 2;

        if (nums[mid] == target){
            last_idx = mid;
            left = mid + 1;
        }
        else if (nums[mid] < target){
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    output[0] = first_idx;
    output[1] = last_idx;
    *returnSize = 2;

    return output;
}