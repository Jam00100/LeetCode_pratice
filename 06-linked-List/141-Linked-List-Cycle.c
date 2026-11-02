#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Floyd's Cycle Detection Algorithm	Floyd 判圈演算法	使用快慢指標偵測 Cycle 的演算法
//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {

    // Step 1：初始化 slow 和 fast
    struct ListNode *slow_step = head;
    struct ListNode *fast_step = head;

    // Step 2：建立 while loop
    // 確保 fast 和 fast->next 都不是 NULL
    while (fast_step != NULL && fast_step->next != NULL){
        // Step 3：slow 移動一格
        slow_step = slow_step->next;

        // Step 4：fast 移動兩格
        fast_step = fast_step->next->next;

        // Step 5：判斷是否相遇
        if (slow_step == fast_step){
            return true;
        }
    }
    // Step 6：沒有 Cycle，回傳 false
    return false;
}

int main(void) {
    struct ListNode node1 = {3, NULL};
    struct ListNode node2 = {2, NULL};
    struct ListNode node3 = {0, NULL};
    struct ListNode node4 = {-4, NULL};

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    // pos = 1，最後一個節點連回 node2
    node4.next = &node2;

    bool result = hasCycle(&node1);

    printf("%s\n", result ? "true" : "false");

    return 0;
}