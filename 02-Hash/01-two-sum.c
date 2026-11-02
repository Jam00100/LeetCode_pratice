/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

// int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
//     for (int i = 0; i < numsSize; i++){
//         for (int j = 0; j < numsSize; j++){
//             if (nums[i] + nums[j] == target && i != j){
//                 int* result = malloc(2 * sizeof(int));

//                 result[0] = i;
//                 result[1] = j;

//                 *returnSize = 2;

//                 return result;
//             }
//         }
//     }
//     *returnSize = 0;
//     return NULL;
// }

// 利用hash
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdint.h>
#include <limits.h>

// Hash Table 每個位置儲存的資料
typedef struct {
    int key;       // nums 裡面的數字
    int value;     // 對應的 index
    bool used;     // 這個位置是否已使用
} Entry;

// Hash Function
size_t hash(int key, size_t tableSize) {
    return (size_t)((uint32_t)key % tableSize);
}

// 插入 key value
void insert(Entry* table, size_t tableSize, int key, int value) {
    size_t index = hash(key, tableSize);

    // Collision：往下一個位置尋找
    while (table[index].used) {

        // 如果 key 已存在，更新 value
        if (table[index].key == key) {
            table[index].value = value;
            return;
        }

        index = (index + 1) % tableSize;
    }

    table[index].key = key;
    table[index].value = value;
    table[index].used = true;
}

// 搜尋 key，找到就透過 value 回傳 index
bool search(Entry* table, size_t tableSize, int key, int* value) {
    size_t index = hash(key, tableSize);

    while (table[index].used) {

        if (table[index].key == key) {
            *value = table[index].value;
            return true;
        }

        index = (index + 1) % tableSize;
    }

    return false;
}

// LeetCode Two Sum
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    *returnSize = 0;

    if (numsSize < 2) {
        return NULL;
    }

    // 容量設為輸入數量的兩倍以上
    size_t tableSize = (size_t)numsSize * 2 + 1;

    // calloc：配置並初始化 Hash Table
    Entry* table = calloc(tableSize, sizeof(Entry));

    if (table == NULL) {
        return NULL;
    }

    for (int i = 0; i < numsSize; i++) {

        int current = nums[i];

        // 用較大的整數型別避免相減溢位
        long long difference = (long long)target - current;

        int previousIndex;

        if (difference >= INT_MIN &&
            difference <= INT_MAX &&
            search(table, tableSize, (int)difference, &previousIndex)) {

            int* result = malloc(2 * sizeof(int));

            if (result == NULL) {
                free(table);
                return NULL;
            }

            result[0] = previousIndex;
            result[1] = i;

            *returnSize = 2;

            free(table);
            return result;
        }

        // 沒找到就記錄目前的數字和 index
        insert(table, tableSize, current, i);
    }

    free(table);
    return NULL;
}