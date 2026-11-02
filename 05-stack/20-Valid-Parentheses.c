#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    int len = strlen(s);

    // 配置 Stack 空間
    char* stack = malloc(len * sizeof(char));

    if (stack == NULL && len > 0) {
        return false;
    }

    int top = -1;

    for (int i = 0; i < len; i++) {
        char current = s[i];

        // Step 1：遇到左括號，Push
        if (current == '(' ||
            current == '[' ||
            current == '{') {

            stack[++top] = current;
        }

        // Step 2：遇到右括號
        else {

            // Stack 為空，無法配對
            if (top == -1) {
                free(stack);
                return false;
            }

            // 取得 Stack Top
            char last = stack[top];

            // 檢查是否配對
            if ((current == ')' && last == '(') ||
                (current == ']' && last == '[') ||
                (current == '}' && last == '{')) {

                // Pop
                top--;
            }
            else {
                free(stack);
                return false;
            }
        }
    }

    // Step 3：檢查 Stack 是否為空
    bool result = (top == -1);

    free(stack);

    return result;
}