/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int* array = malloc(2 * numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        array[i] = nums[i];
    }

    for (int i = 0; i < numsSize; i++) {
        int new_idx = numsSize + i;
        array[new_idx] = nums[i];
    }

    *returnSize = 2 * numsSize;

    return array;
}