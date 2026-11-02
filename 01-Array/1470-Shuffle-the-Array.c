#include <stdlib.h>

int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
    int* output = malloc(numsSize * sizeof(int));
    int new_idx = 0;

    for (int i = 0; i < n; i++) {

        int x = nums[i];
        int y = nums[i + n];

        output[new_idx] = x;
        new_idx = new_idx + 1;

        output[new_idx] = y;
        new_idx = new_idx + 1;
    }

    *returnSize = numsSize;

    return output;
}