#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isPalindrome(char* s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        // 如果左邊不是字母或數字，直接往右跳過
        if (!isalnum((unsigned char)s[left])) {
            left++;
        }
        // 如果右邊不是字母或數字，直接往左跳過
        else if (!isalnum((unsigned char)s[right])) {
            right--;
        }
        // 兩邊都是字母數字，轉小寫後進行比對
        else {
            if (tolower((unsigned char)s[left]) != tolower((unsigned char)s[right])) {
                return false; // 不相同就不是回文
            }
            left++;
            right--;
        }
    }
    return true;
}