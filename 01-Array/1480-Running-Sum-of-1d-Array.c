#include <stdio.h>
#include <stdlib.h>

int* runningSum(int* nums, int numsSize, int* returnSize) {
    int* array = malloc(numsSize * sizeof(int));
    int sums = 0;

    for (int i = 0; i < numsSize; i++) {
        sums = nums[i] + sums;
        array[i] = sums;
    }

    *returnSize = numsSize;

    return array;
}