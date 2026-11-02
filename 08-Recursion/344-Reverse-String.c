#include <stdio.h>
#include <stdlib.h>

void helper(char* s, int left, int right) {
    // Base Case
    if (left >= right) {
        return;
    }

    // Step 1：交換 s[left] 和 s[right]
    char tmp = s[left];
    s[left] = s[right];
    s[right] = tmp;

    // Step 2：遞迴呼叫 helper()
    helper(s, left + 1, right - 1);

}

void reverseString(char* s, int sSize) {
    helper(s, 0, sSize - 1);
}