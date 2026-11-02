#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

// ========================================
// 1. Hash Table Entry
// ========================================
typedef struct {
    int key;
    bool used;
    bool added;
} Entry;

// ========================================
// 2. Hash Function
// ========================================
size_t hash(int key, size_t tableSize) {
    size_t index = (size_t)((uint32_t)key % tableSize);

    printf("    hash(%d) = %zu\n", key, index);

    return index;
}

// ========================================
// 3. Print Hash Table
// ========================================
void printTable(Entry* table, size_t tableSize) {
    printf("\n    Current Hash Table:\n");
    printf("    %-8s %-10s %-8s %-8s\n",
           "Index", "Key", "Used", "Added");

    for (size_t i = 0; i < tableSize; i++) {
        if (table[i].used) {
            printf("    %-8zu %-10d %-8s %-8s\n",
                   i,
                   table[i].key,
                   "true",
                   table[i].added ? "true" : "false");
        } else {
            printf("    %-8zu %-10s %-8s %-8s\n",
                   i, "-", "false", "false");
        }
    }

    printf("\n");
}

// ========================================
// 4. Insert
// ========================================
void insert(Entry* table, size_t tableSize, int key) {
    printf("\n  [INSERT] key = %d\n", key);

    size_t index = hash(key, tableSize);

    while (table[index].used) {
        printf("    Index %zu is occupied by key %d\n",
               index, table[index].key);

        if (table[index].key == key) {
            printf("    Duplicate key! Skip insertion.\n");
            return;
        }

        size_t nextIndex = (index + 1) % tableSize;

        printf("    Collision! Move from index %zu to %zu\n",
               index, nextIndex);

        index = nextIndex;
    }

    table[index].key = key;
    table[index].used = true;
    table[index].added = false;

    printf("    Insert key %d at index %zu\n", key, index);
}

// ========================================
// 5. Search
// ========================================
Entry* search(Entry* table, size_t tableSize, int key) {
    printf("\n  [SEARCH] key = %d\n", key);

    size_t index = hash(key, tableSize);

    while (table[index].used) {
        printf("    Check index %zu: stored key = %d\n",
               index, table[index].key);

        if (table[index].key == key) {
            printf("    Found key %d at index %zu!\n",
                   key, index);

            return &table[index];
        }

        size_t nextIndex = (index + 1) % tableSize;

        printf("    Key mismatch. Move to index %zu\n",
               nextIndex);

        index = nextIndex;
    }

    printf("    Index %zu is empty. Key %d not found.\n",
           index, key);

    return NULL;
}

// ========================================
// 6. LeetCode 349
// ========================================
int* intersection(
    int* nums1,
    int nums1Size,
    int* nums2,
    int nums2Size,
    int* returnSize
) {
    *returnSize = 0;

    if (nums1Size == 0 || nums2Size == 0) {
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
        fprintf(stderr, "Hash Table allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    int* result = malloc((size_t)nums1Size * sizeof(int));

    if (result == NULL) {
        free(table);
        fprintf(stderr, "Result allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    // ====================================
    // STEP 1: Initialize
    // ====================================
    printf("\n========================================\n");
    printf("STEP 1: Initialize Hash Table\n");
    printf("========================================\n");

    printf("nums1Size = %d\n", nums1Size);
    printf("nums2Size = %d\n", nums2Size);
    printf("tableSize = %zu\n", tableSize);

    printTable(table, tableSize);

    // ====================================
    // STEP 2: Insert nums1
    // ====================================
    printf("\n========================================\n");
    printf("STEP 2: Insert nums1 into Hash Table\n");
    printf("========================================\n");

    for (int i = 0; i < nums1Size; i++) {
        printf("\n--- nums1[%d] = %d ---\n", i, nums1[i]);

        insert(table, tableSize, nums1[i]);

        printTable(table, tableSize);
    }

    // ====================================
    // STEP 3: Search nums2
    // ====================================
    printf("\n========================================\n");
    printf("STEP 3: Search nums2\n");
    printf("========================================\n");

    for (int i = 0; i < nums2Size; i++) {
        int current = nums2[i];

        printf("\n--- nums2[%d] = %d ---\n", i, current);

        Entry* entry = search(table, tableSize, current);

        if (entry == NULL) {
            printf("    Result: %d is not in nums1. Skip.\n",
                   current);
        } else if (entry->added) {
            printf("    Result: %d was already added. Skip.\n",
                   current);
        } else {
            result[*returnSize] = current;
            (*returnSize)++;

            entry->added = true;

            printf("    Result: Add %d to intersection!\n",
                   current);
        }

        printf("    Current result: [");

        for (int j = 0; j < *returnSize; j++) {
            printf("%s%d", j == 0 ? "" : ", ", result[j]);
        }

        printf("]\n");

        printTable(table, tableSize);
    }

    // ====================================
    // STEP 4: Cleanup
    // ====================================
    printf("\n========================================\n");
    printf("STEP 4: Cleanup\n");
    printf("========================================\n");

    printf("Free Hash Table memory.\n");
    free(table);

    return result;
}

// ========================================
// 7. Main: Local Testing
// ========================================
int main(void) {
    // 這組資料會產生 Hash Collision
    int nums1[] = {1, 10, 19, 1};
    int nums2[] = {19, 10, 10, 20, 1};

    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);

    printf("Input nums1: [");
    for (int i = 0; i < nums1Size; i++) {
        printf("%s%d", i == 0 ? "" : ", ", nums1[i]);
    }
    printf("]\n");

    printf("Input nums2: [");
    for (int i = 0; i < nums2Size; i++) {
        printf("%s%d", i == 0 ? "" : ", ", nums2[i]);
    }
    printf("]\n");

    int returnSize = 0;

    int* result = intersection(
        nums1,
        nums1Size,
        nums2,
        nums2Size,
        &returnSize
    );

    printf("\n========================================\n");
    printf("FINAL RESULT\n");
    printf("========================================\n");

    printf("Intersection: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%s%d", i == 0 ? "" : ", ", result[i]);
    }
    printf("]\n");

    printf("returnSize = %d\n", returnSize);

    free(result);

    return 0;
}