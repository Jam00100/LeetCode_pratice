#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int left = 0;
    int right = 0;
    int max_length;
    int len = strlen(s);

    bool seen[256] = {false};

    while (right < len){
        // Step 1：目前字元重複，縮小 Window
        while (seen[(unsigned char)s[right]]) {
            seen[(unsigned char)s[left]] = false;
            left++;
        }
        // Step 2：加入目前字元
        seen[(unsigned char)s[right]] = true;

        // Step 3：更新最長長度
        int window_size = right - left + 1;

        if (window_size > max_length) {
            max_length = window_size;
        }

        // Step 4：擴大 Window
        right++;
    }

    return max_length;
}