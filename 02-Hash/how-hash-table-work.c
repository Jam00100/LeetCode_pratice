#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int key;
    bool used;
} Entry;

// Hash Function
int hash(int key, int tableSize) {
    return (int)(((long long)key % tableSize
                  + tableSize) % tableSize);
}

// Search
bool search(Entry* table, int tableSize, int key) {
    int index = hash(key, tableSize);

    printf("Search key = %d, hash index = %d\n", key, index);

    while (table[index].used) {
        printf("  Check index %d, stored key = %d\n",
               index, table[index].key);

        if (table[index].key == key) {
            printf("  Found duplicate!\n");
            return true;
        }

        index = (index + 1) % tableSize;
    }

    printf("  Key not found\n");
    return false;
}

// Insert
void insert(Entry* table, int tableSize, int key) {
    int index = hash(key, tableSize);

    printf("Insert key = %d, hash index = %d\n", key, index);

    while (table[index].used) {
        if (table[index].key == key) {
            return;
        }

        printf("  Collision at index %d\n", index);

        index = (index + 1) % tableSize;
    }

    table[index].key = key;
    table[index].used = true;

    printf("  Stored at index %d\n", index);
}

// Print Hash Table
void printTable(Entry* table, int tableSize) {
    printf("\nCurrent Hash Table:\n");

    for (int i = 0; i < tableSize; i++) {
        if (table[i].used) {
            printf("  [%d] key = %d\n", i, table[i].key);
        } else {
            printf("  [%d] empty\n", i);
        }
    }

    printf("\n");
}

// LeetCode 217
bool containsDuplicate(int* nums, int numsSize) {
    int tableSize = numsSize * 2 + 1;

    Entry* table = calloc(tableSize, sizeof(Entry));

    if (table == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numsSize; i++) {
        int current = nums[i];

        printf("\n========== i = %d ==========\n", i);

        if (search(table, tableSize, current)) {
            printTable(table, tableSize);
            free(table);
            return true;
        }

        insert(table, tableSize, current);
        printTable(table, tableSize);
    }

    free(table);
    return false;
}

int main(void) {
    int nums[] = {1, 8, 15, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    bool result = containsDuplicate(nums, numsSize);

    printf("\nFinal result: %s\n", result ? "true" : "false");

    return 0;
}