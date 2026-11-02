from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:

        prev = None
        current = head

        while current is not None:
            # Step 1：保存下一個節點
            next_node = current.next
            # Step 2：反轉 current.next
            current.next = prev
            # Step 3：移動 prev
            prev = current
            # Step 4：移動 current
            current = next_node

        # 回傳反轉後的 head
        return prev

node1 = ListNode(1)
node2 = ListNode(2)
node3 = ListNode(3)
node4 = ListNode(4)

node1.next = node2
node2.next = node3
node3.next = node4

solution = Solution()

new_head = solution.reverseList(node1)

# 印出反轉後的 Linked List
current = new_head

while current is not None:
    print(current.val, end=" -> ")
    current = current.next

print("None")