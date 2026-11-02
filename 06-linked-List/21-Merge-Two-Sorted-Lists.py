# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(self, list1: ListNode | None, list2: ListNode | None) -> ListNode | None:

        dummy = ListNode(0)
        current = dummy

        while list1 is not None and list2 is not None:

            if list1.val <= list2.val:
                # Step 1：連接 list1 的節點
                current.next = list1
                # Step 2：list1 前進
                list1 = list1.next
            else:
                # Step 3：連接 list2 的節點
                current.next = list2
                # Step 4：list2 前進
                list2 = list2.next

            # Step 5：current 前進
            current = current.next

            # Step 6：連接剩下的 Linked List
        if list1 == None:
            current.next = list2
        else:
            current.next = list1

        # Step 7：回傳正確的 head
        dummy = dummy.next
        return dummy


# =============================
# 建立 Linked List
# =============================
def build_linked_list(values):
    if not values:
        return None

    head = ListNode(values[0])
    current = head

    for value in values[1:]:
        current.next = ListNode(value)
        current = current.next

    return head


# =============================
# 印出 Linked List
# =============================
def print_linked_list(head):
    current = head

    while current is not None:
        print(current.val, end=" -> ")
        current = current.next

    print("None")


# =============================
# Test Case 1
# =============================
list1 = build_linked_list([1, 2, 4])
list2 = build_linked_list([1, 3, 4])

solution = Solution()
result = solution.mergeTwoLists(list1, list2)

print("Test Case 1:")
print_linked_list(result)


# =============================
# Test Case 2：兩條都是空的
# =============================
list1 = build_linked_list([])
list2 = build_linked_list([])

result = solution.mergeTwoLists(list1, list2)

print("Test Case 2:")
print_linked_list(result)


# =============================
# Test Case 3：其中一條為空
# =============================
list1 = build_linked_list([])
list2 = build_linked_list([0])

result = solution.mergeTwoLists(list1, list2)

print("Test Case 3:")
print_linked_list(result)