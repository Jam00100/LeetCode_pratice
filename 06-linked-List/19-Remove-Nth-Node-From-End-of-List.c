#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy = {0, NULL};
    dummy.next = head;

    struct ListNode *fast = &dummy;
    struct ListNode *slow = &dummy;

    for (int i = 0; i < n + 1; i++){
        fast = fast -> next;
    }
    while (fast != NULL){
        fast = fast -> next;
        slow = slow -> next;
    }
    
    // free  memory()
    struct ListNode *to_delete = slow->next;
    slow->next = to_delete->next;
    free(to_delete);
    // slow -> next = slow -> next -> next;

    return dummy.next;
}