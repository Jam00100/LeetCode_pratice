#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    int key;
    int value;
    bool used;
} Entry;

size_t hash(int key, size_t tableSize){
    return (size_t) ((uint32_t)key % tableSize);
}

void insert(Entry* table, size_t tableSize, int key, int value){
    size_t index = hash(key, tableSize);

    while (table[index].used){
        if (table[index].key == key){
            table[index].value = value;
            return;
        }
        index = (index + 1) % tableSize;
    }
    table[index].key = key;
    table[index].value = value;
    table[index].used = true;
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

int totalFruit(int* fruits, int fruitsSize) {
    int left = 0;
    int max_length = 0;
    int distinct = 0;

    size_t tableSize = (size_t)fruitsSize * 2 + 1;

    Entry* count = calloc(tableSize, sizeof(Entry));

    if (count == NULL) {
        return 0;
    }

    for (int right = 0; right < fruitsSize; right++) {
        int current = fruits[right];
        int frequency = 0;

        // Step 1：加入右側水果
        search(count, tableSize, current, &frequency);

        // 原本數量是 0，代表 Window 增加一種水果
        if (frequency == 0) {
            distinct++;
        }

        insert(count, tableSize, current, frequency + 1);

        // Step 2：超過兩種水果，縮小 Window
        while (distinct > 2) {
            int left_fruit = fruits[left];
            int left_frequency = 0;

            search(count, tableSize, left_fruit, &left_frequency);

            // 減少左側水果的數量
            insert(count, tableSize, left_fruit, left_frequency - 1);

            // 該水果在 Window 中已經不存在
            if (left_frequency - 1 == 0) {
                distinct--;
            }

            left++;
        }

        // Step 3：更新最長長度
        int window_size = right - left + 1;

        if (window_size > max_length) {
            max_length = window_size;
        }
    }

    free(count);
    return max_length;
}