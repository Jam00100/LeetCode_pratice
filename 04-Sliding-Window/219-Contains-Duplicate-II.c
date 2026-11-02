#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    int key;
    int value;
    bool used;
} Entry;

// Hash Function
size_t hash(int key, size_t tableSize) {
    return (size_t)(uint32_t)key % tableSize;
}

// Insert
void insert(Entry* table, size_t tableSize, int key, int value) {
    size_t index = hash(key, tableSize);

    while (table[index].used) {
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

// Search
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

// LeetCode 219
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    size_t tableSize = (size_t)numsSize * 2 + 1;

    Entry* table = calloc(tableSize, sizeof(Entry));

    if (table == NULL) {
        return false;
    }

    for (int i = 0; i < numsSize; i++) {
        int current = nums[i];
        int previousIndex;

        // 檢查數字是否出現過
        if (search(table, tableSize, current, &previousIndex)) {

            // 因為 i 一定大於 previousIndex，不需要 abs()
            int distance = i - previousIndex;

            if (distance <= k) {
                free(table);
                return true;
            }
        }

        // 更新數字最後出現的 Index
        insert(table, tableSize, current, i);
    }

    free(table);
    return false;
}