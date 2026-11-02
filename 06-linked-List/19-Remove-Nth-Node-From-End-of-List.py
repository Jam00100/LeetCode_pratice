# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head: ListNode | None, n: int) -> ListNode | None:

        dummy = ListNode(0)
        # 讓dummy和head相連接
        dummy.next = head
        fast = dummy
        slow = dummy

        # 讓pointer fast先走N+1
        for _ in range(n + 1):
            fast = fast.next

        # 讓fast and slow pointer開始一起走直到fast == None
        while fast != None:
            fast = fast.next
            slow = slow.next
        
        slow.next = slow.next.next
        return dummy.next