# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        # 解題思路：Recursion（遞迴）
        # 1. 比較 list1 和 list2 目前節點的數值，選擇較小的節點。
        # 2. 將較小節點的 next，接上剩餘兩條 Linked List 的合併結果。
        # 3. 透過遞迴，不斷縮小需要合併的範圍。
        # 4. 當其中一條 Linked List 為 None，直接回傳另一條。
        # 5. 遞迴結果逐層回傳，完成所有節點的連接。

        # Base Case：其中一條 Linked List 已經沒有節點
        if not list1:
            return list2

        if not list2:
            return list1

        # Recursive Case：比較兩個節點的數值
        if list1.val <= list2.val:
            # 選擇 list1 作為目前合併結果的 Head。
            # 因為 list1 已經被選擇，下一層要從 list1.next 開始。
            # 遞迴合併 list1 剩下的節點與整條 list2。
            # 將遞迴回傳的 Head 接到 list1.next。
            list1.next = self.mergeTwoLists(list1.next, list2)

            # 回傳目前選擇的節點，讓上一層可以連接它。
            return list1

        else:
            # 選擇 list2 作為目前合併結果的 Head。
            # 因為 list2 已經被選擇，下一層要從 list2.next 開始。
            # 遞迴合併整條 list1 與 list2 剩下的節點。
            # 將遞迴回傳的 Head 接到 list2.next。
            list2.next = self.mergeTwoLists(list1, list2.next)

            # 回傳目前選擇的節點，讓上一層可以連接它。
            return list2