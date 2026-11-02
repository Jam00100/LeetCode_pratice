#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Solution 1: frequency array
bool canConstruct(char* ransomNote, char* magazine) {
    int count[26] = {0};

    for (int i = 0; magazine[i] != '\0'; i++){
        count[magazine[i] - 'a'] += 1;
    }
    for (int i = 0; ransomNote[i] != '\0'; i++){
        int index = ransomNote[i] - 'a';
        count[index] -= 1;
        
        if (count[index] < 0){
            return false;
        }

    }
    return true;
}

// solution 2: Hash table
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char key;
    int value;
    bool used;
} Entry;

// Hash Function
int hash(char key, int tableSize) {
    return (unsigned char)key % tableSize;
}

// 新增字元或增加出現次數
void insert(Entry* table, int tableSize, char key) {
    int index = hash(key, tableSize);

    while (table[index].used) {
        if (table[index].key == key) {
            table[index].value++;
            return;
        }

        index = (index + 1) % tableSize;
    }

    table[index].key = key;
    table[index].value = 1;
    table[index].used = true;
}

// 消耗一個字元
bool consume(Entry* table, int tableSize, char key) {
    int index = hash(key, tableSize);

    while (table[index].used) {
        if (table[index].key == key) {
            if (table[index].value <= 0) {
                return false;
            }

            table[index].value--;
            return true;
        }

        index = (index + 1) % tableSize;
    }

    return false;
}

// LeetCode 383
bool canConstruct(char* ransomNote, char* magazine) {
    int ransomLen = strlen(ransomNote);
    int magazineLen = strlen(magazine);

    if (ransomLen > magazineLen) {
        return false;
    }

    // 26 種字元，配置 53 個位置以降低碰撞
    int tableSize = 53;

    Entry* table = calloc(tableSize, sizeof(Entry));

    if (table == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // 建立 magazine 的字元庫存
    for (int i = 0; magazine[i] != '\0'; i++) {
        insert(table, tableSize, magazine[i]);
    }

    // 使用 ransomNote 所需的字元
    for (int i = 0; ransomNote[i] != '\0'; i++) {
        if (!consume(table, tableSize, ransomNote[i])) {
            free(table);
            return false;
        }
    }

    free(table);
    return true;
}

int main(void) {
    char ransomNote[] = "aab";
    char magazine[] = "abac";

    bool result = canConstruct(ransomNote, magazine);

    printf("Result: %s\n", result ? "true" : "false");

    return 0;
}

