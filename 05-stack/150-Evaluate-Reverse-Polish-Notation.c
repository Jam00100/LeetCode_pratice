#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int evalRPN(char** tokens, int tokensSize) {
    int* stack = malloc(tokensSize * sizeof(int));

    if (stack == NULL) {
        return 0;
    }

    int top = -1;
    int result;

    for (int index = 0; index < tokensSize; index++) {

        char* token = tokens[index];

        if (strcmp(token, "+") == 0 ||
            strcmp(token, "-") == 0 ||
            strcmp(token, "*") == 0 ||
            strcmp(token, "/") == 0) {

            // Pop
            int val2 = stack[top--];
            int val1 = stack[top--];

            if (strcmp(token, "+") == 0) {
                result = val1 + val2;
            }
            else if (strcmp(token, "-") == 0) {
                result = val1 - val2;
            }
            else if (strcmp(token, "*") == 0) {
                result = val1 * val2;
            }
            else {
                result = val1 / val2;
            }

            // Push result
            stack[++top] = result;
        }
        else {
            int value = atoi(token);

            // Push value
            stack[++top] = value;
        }
    }

    int output = stack[top];

    free(stack);

    return output;
}