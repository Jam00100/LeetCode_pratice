#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removeDuplicates(char* s) {
    int len = strlen(s);

    // 配置 Stack，額外保留一格給 '\0'
    char* stack = malloc((len + 1) * sizeof(char));

    if (stack == NULL) {
        return NULL;
    }

    int top = -1;

    for (int i = 0; i < len; i++) {
        char current = s[i];

        // Step 1：Stack 不為空，且 Top 與 current 相同
        if (top >= 0 && stack[top] == current) {

            // Pop
            top--;
        }
        else {

            // Push
            stack[++top] = current;
        }
    }

    // Step 2：加上 C 字串結束符號
    stack[top + 1] = '\0';

    return stack;
}

int main(void) {
    char s[] = "abbaca";

    char* result = removeDuplicates(s);

    if (result == NULL) {
        return 1;
    }

    printf("Input: %s\n", s);
    printf("Output: %s\n", result);

    // 釋放 malloc 配置的記憶體
    free(result);

    return 0;
}