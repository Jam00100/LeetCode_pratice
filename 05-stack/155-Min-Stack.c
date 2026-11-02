#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// typedef struct {
//     int* stack;
//     int* min_stack;
//     int top;
//     int capacity;
// } MinStack;

// MinStack* minStackCreate() {

//     MinStack* obj = malloc(sizeof(MinStack));

//     if (obj == NULL) {
//         return NULL;
//     }

//     obj->top = -1;

//     return obj;
// }

// void minStackPush(MinStack* obj, int value) {
//     // Step 1：將 top 加 1
//     obj -> top += 1;
//     // Step 2：把 value 存入 stack[top]
//     obj -> stack[obj -> top] = value;
//     // Step 3：更新 min_stack[top]
//     if (obj -> top == 0) {
//         // 如果是第一個元素，最小值就是 value 本身
//         obj -> min_stack[obj -> top] = value;
//     }
//     else {
//         int pre_min = obj -> min_stack[obj -> top-1];
//         if (value < pre_min){
//             obj -> min_stack[obj -> top] = value;
//         }
//         else{
//             obj -> min_stack[obj -> top] = pre_min;
//         }
//     }
// }

// void minStackPop(MinStack* obj) {
//     obj -> top -= 1;
// }

// int minStackTop(MinStack* obj) {
//     return obj -> stack[obj -> top];
// }

// int minStackGetMin(MinStack* obj) {
//     return obj->min_stack[obj->top];
// }

// void minStackFree(MinStack* obj) {
//     if (obj != NULL){
//         free(obj);
//     }
// }


#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdint.h>

typedef struct {
    int* stack;
    int* min_stack;
    int top;
    int capacity;
} MinStack;


MinStack* minStackCreate() {
    MinStack* obj = malloc(sizeof(MinStack));

    if (obj == NULL) {
        return NULL;
    }

    obj->top = -1;
    obj->capacity = 4;

    obj->stack = malloc(obj->capacity * sizeof(int));
    obj->min_stack = malloc(obj->capacity * sizeof(int));

    if (obj->stack == NULL || obj->min_stack == NULL) {
        free(obj->stack);
        free(obj->min_stack);
        free(obj);
        return NULL;
    }

    return obj;
}


void minStackPush(MinStack* obj, int value) {

    // Step 1：檢查容量
    if (obj->top + 1 >= obj->capacity) {

        int new_capacity = obj->capacity * 2;

        int* new_stack = malloc(new_capacity * sizeof(int));
        int* new_min_stack = malloc(new_capacity * sizeof(int));

        // 兩個新陣列都配置成功，才進行替換
        if (new_stack == NULL || new_min_stack == NULL) {
            free(new_stack);
            free(new_min_stack);
            return;
        }

        // 複製原本的資料
        for (int i = 0; i <= obj->top; i++) {
            new_stack[i] = obj->stack[i];
            new_min_stack[i] = obj->min_stack[i];
        }

        // 釋放舊陣列
        free(obj->stack);
        free(obj->min_stack);

        // 更新指標與容量
        obj->stack = new_stack;
        obj->min_stack = new_min_stack;
        obj->capacity = new_capacity;
    }

    // Step 2：Push
    obj->top++;
    obj->stack[obj->top] = value;

    // Step 3：更新最小值
    if (obj->top == 0) {
        obj->min_stack[obj->top] = value;
    }
    else {
        int pre_min = obj->min_stack[obj->top - 1];

        if (value < pre_min) {
            obj->min_stack[obj->top] = value;
        }
        else {
            obj->min_stack[obj->top] = pre_min;
        }
    }
}


void minStackPop(MinStack* obj) {
    obj->top--;
}


int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}


int minStackGetMin(MinStack* obj) {
    return obj->min_stack[obj->top];
}


void minStackFree(MinStack* obj) {
    if (obj == NULL) {
        return;
    }

    free(obj->stack);
    free(obj->min_stack);
    free(obj);
}