#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

int main(void) {
    ListNode* node1 = malloc(sizeof(ListNode));
    ListNode* node2 = malloc(sizeof(ListNode));
    ListNode* node3 = malloc(sizeof(ListNode));

    if (node1 == NULL || node2 == NULL || node3 == NULL) {
        free(node1);
        free(node2);
        free(node3);
        return 1;
    }

    node1->val = 10;
    node2->val = 20;
    node3->val = 30;

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    ListNode* head = node1;

    // 遍歷
    ListNode* current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }

    free(node3);
    free(node2);
    free(node1);

    return 0;
}