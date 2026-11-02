#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// //solution 1
// bool containsDuplicate(int* nums, int numsSize) {
//     for (int i = 0; i < numsSize; i++) {
//         for (int j = i + 1; j < numsSize; j++) {
//             if (nums[i] == nums[j]) {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// //solution 2
// int compare(const void* a, const void* b) {
//     int x = *(const int*)a;
//     int y = *(const int*)b;

//     return (x > y) - (x < y);
// }

// bool containsDuplicate(int* nums, int numsSize) {
//     qsort(nums, numsSize, sizeof(int), compare);

//     for (int i = 1; i < numsSize; i++) {
//         if (nums[i] == nums[i - 1]) {
//             return true;
//         }
//     }

//     return false;
// }

// solution 3 Hash
typedef struct 
{
	// 儲存數字和是否出現過
	int key;
	bool used;
} Entry;

// 建立hash function 為key分配位置
int hash(int key, int tableSize) {
	return (int)(((long long)key % tableSize+ tableSize) % tableSize);
}
// insert function
void insert(Entry* table, int tableSize, int key) {
	int index = hash(key, tableSize);

	while (table[index].used) {
		if (table[index].key == key) {
			return;
		}

		index = (index + 1) % tableSize;
	}

	table[index].key = key;
	table[index].used = true;
}

// search function
bool search(Entry* table, int tableSize, int key) {
    int index = hash(key, tableSize);

    while (table[index].used) {

        if (table[index].key == key) {
            return true;
        }

        index = (index + 1) % tableSize;
    }

    return false;
}

bool containsDuplicate(int* nums, int numsSize) {
    int tableSize = numsSize * 2 + 1;

    Entry* table = calloc(tableSize, sizeof(Entry));

    if (table == NULL) {
        return false;
    }

    for (int i = 0; i < numsSize; i++) {
        int current = nums[i];

        if (search(table, tableSize, current)) {
            free(table);
            return true;
        }

        insert(table, tableSize, current);
    }

    free(table);
    return false;
}

int main(void) {
    int nums[] = {1, 8, 15, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    bool result = containsDuplicate(nums, numsSize);

    printf("Contains Duplicate: %s\n", result ? "true" : "false");

    return 0;
}