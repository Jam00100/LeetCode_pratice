#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {

    struct ListNode* prev = NULL;
    struct ListNode* current = head;

    while (current != NULL){
        struct ListNode* next_node = current -> next;
        current -> next = prev;
        prev = current;
        current = next_node;
    }

    return prev;
}