from typing import Optional

# Floyd's Cycle Detection Algorithm	Floyd 判圈演算法	使用快慢指標偵測 Cycle 的演算法

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        #
        fast_step = head
        slow_step = head

        while fast_step is not None and fast_step.next is not None:
            # slow 前進 1 個節點
            slow_step = slow_step.next
            # fast 前進 2 個節點
            fast_step = fast_step.next.next
            # 判斷是否相遇
            if fast_step is slow_step:
                return True
            pass
        return False


test = Solution()
# 建立 Linked List
node1 = ListNode(3)
node2 = ListNode(2)
node3 = ListNode(0)
node4 = ListNode(-4)

node1.next = node2
node2.next = node3
node3.next = node4

# pos = 1，最後一個節點連回 node2
node4.next = node2

test = Solution()
x = test.hasCycle(head=node1)

print(x)  # True