#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isAnagram(char* s, char* t) {
    // 比較字串長度
    int len_s = strlen(s);
    int len_t = strlen(t);

    if (len_s != len_t) {
        return false;
    }

    // 建立 26 個字母的頻率array
    int count[26] = {0};

    // s 的字元次數 +1 (ASCII)
    // 'a' - 'a' = 0
    // 'b' - 'a' = 1
    // 'c' - 'a' = 2
    // ...
    // 'z' - 'a' = 25
    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    // 檢查是否全部抵銷
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;
        }
    }

    return true;
}

int main(void) {
    char s[] = "anagram";
    char t[] = "nagaram";

    bool result = isAnagram(s, t);

    printf("Result: %s\n", result ? "true" : "false");

    return 0;
}