#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 遞迴產生所有子集合
void backtrack(int* nums, int numsSize, int start, int* path, int pathSize, int** result, int* returnSize, int* columnSizes) {
    // Step 1：記錄目前的子集合
    int* subset = malloc(pathSize * sizeof(int));

    for (int i = 0; i < pathSize; i++) {
        subset[i] = path[i];
    }

    result[*returnSize] = subset;
    columnSizes[*returnSize] = pathSize;
    (*returnSize)++;

    // Step 2：探索剩下的元素
    for (int i = start; i < numsSize; i++) {

        // Choose：選擇 nums[i]
        path[pathSize] = nums[i];

        // Explore：遞迴探索
        backtrack(nums, numsSize, i + 1, path, pathSize + 1, result, returnSize, columnSizes);

        // Unchoose：
        // pathSize 是值傳遞，返回後仍是原本的大小。
        // 下一次迴圈會覆寫 path[pathSize]。
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // 子集合總數 = 2^numsSize
    int total = 1 << numsSize;

    // 配置結果陣列
    int** result = malloc(total * sizeof(int*));

    // 配置每個子集合的長度陣列
    *returnColumnSizes = malloc(total * sizeof(int));

    // 配置暫存路徑
    int* path = malloc(numsSize * sizeof(int));

    // 初始化結果數量
    *returnSize = 0;

    // 開始 Backtracking
    backtrack(nums, numsSize, 0, path, 0, result, returnSize, *returnColumnSizes);

    // 暫存路徑已經不需要
    free(path);

    return result;
}