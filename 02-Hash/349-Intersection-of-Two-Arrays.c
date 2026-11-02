#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    int key;
    bool used;
    bool added;
} Entry;

// Hash Function
size_t hash(int key, size_t tableSize) {
    return (size_t)((uint32_t)key % tableSize);
}

// Insert
void insert(Entry* table, size_t tableSize, int key) {
    size_t index = hash(key, tableSize);

    while (table[index].used) {
        // 如果 key 已存在，不需要重複插入
        if (table[index].key == key) {
            return;
        }

        // Collision：往下一格尋找
        index = (index + 1) % tableSize;
    }

    table[index].key = key;
    table[index].used = true;
    table[index].added = false;
}

// Search
Entry* search(Entry* table, size_t tableSize, int key) {
    size_t index = hash(key, tableSize);

    while (table[index].used) {
        if (table[index].key == key) {
            return &table[index];
        }

        index = (index + 1) % tableSize;
    }

    return NULL;
}

// LeetCode 349
int* intersection(
    int* nums1,
    int nums1Size,
    int* nums2,
    int nums2Size,
    int* returnSize
) {
    *returnSize = 0;

    // 交集數量不可能超過較短陣列的長度
    int maxSize = nums1Size < nums2Size ? nums1Size : nums2Size;

    if (maxSize == 0) {
        return NULL;
    }

    // 使用較短的陣列建立 Hash Table
    if (nums1Size > nums2Size) {
        int* tempNums = nums1;
        nums1 = nums2;
        nums2 = tempNums;

        int tempSize = nums1Size;
        nums1Size = nums2Size;
        nums2Size = tempSize;
    }

    size_t tableSize = (size_t)nums1Size * 2 + 1;

    Entry* table = calloc(tableSize, sizeof(Entry));
    if (table == NULL) {
        return NULL;
    }

    int* result = malloc((size_t)maxSize * sizeof(int));
    if (result == NULL) {
        free(table);
        return NULL;
    }

    // Step 1：把 nums1 插入 Hash Table
    for (int i = 0; i < nums1Size; i++) {
        insert(table, tableSize, nums1[i]);
    }

    // Step 2：遍歷 nums2，尋找共同元素
    for (int i = 0; i < nums2Size; i++) {
        int current = nums2[i];

        Entry* entry = search(table, tableSize, current);

        // 找到交集，而且還沒有加入答案
        if (entry != NULL && !entry->added) {
            result[*returnSize] = current;
            (*returnSize)++;

            // 標記已加入，避免重複
            entry->added = true;
        }
    }

    free(table);
    return result;
}