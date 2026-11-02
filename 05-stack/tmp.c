#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    int len = strlen(s);

    char* stack = malloc(len * sizeof(char));

    if (stack == NULL && len > 0) {
        return false;
    }
    // stack 的最後一項
    int top = -1;

    for (int i = 0; i < len; i++){
        char current = s[i];

        // step1 如果遇到左括號 push
        if (current == '(' || current == '[' || current == '{') {
            stack[++top] = current;
        }
        else {
            if (top == -1){
                free(stack);
                return false;
            }

            char last = stack[top];

            if ((current == ')' && last == '(') || (current == ']' && last == '[') || (current == '}' && last == '{')){
                top --;
            }
            else{
                free(stack);
                return false;
            }
        }
    }
    bool result = (top == -1);
    free(stack);
    return result;
}