#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// soultuion 1 two pointers
// int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
//     int left = 0;
//     int right = numbersSize - 1;

//     // 配置兩個 int 的記憶體
//     int* output = malloc(2 * sizeof(int));

//     if (output == NULL) {
//         *returnSize = 0;
//         return NULL;
//     }

//     while (left < right) {
//         int sum = numbers[left] + numbers[right];

//         if (sum == target) {
//             output[0] = left + 1;
//             output[1] = right + 1;

//             *returnSize = 2;
//             return output;
//         }
//         else if (sum < target) {
//             left++;
//         }
//         else {
//             right--;
//         }
//     }

//     // 題目保證有答案，這裡只是防禦性處理
//     free(output);
//     *returnSize = 0;
//     return NULL;
// }

// soultion 2 Hash
typedef struct {
    int key;
    int value;
    bool used;
} Entry;

// hash function
size_t hash(int key, size_t tableSize) {
    return (size_t)((uint32_t)key % tableSize);
}

// insert
void insert(Entry* table, size_t tableSize, int key, int value){
    // get hash
    size_t index = hash(key, tableSize);

    while (table[index].used){
        // 如果 key 已存在，更新 value
        if (table[index].key == key) {
            table[index].value = value;
            return;
        }
        index = (index + 1) % tableSize;
    }
    table[index].key = key;
    table[index].value = value;
    table[index].used  = true;
}

bool search(Entry* table, size_t tableSize, int key, int *value){
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

        if (difference >= INT_MIN &&difference <= INT_MAX &&
            search(table, tableSize, (int)difference, &previousIndex)) {

            int* result = malloc(2 * sizeof(int));

            if (result == NULL) {
                free(table);
                return NULL;
            }

            result[0] = previousIndex + 1;
            result[1] = i + 1;

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