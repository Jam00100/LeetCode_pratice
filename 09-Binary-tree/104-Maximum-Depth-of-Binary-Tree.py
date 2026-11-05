# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxDepth(self, root: TreeNode | None) -> int:

        if root == None:
            return 0

        # 尋找left/right tree的最深處
        left_max = self.maxDepth(root.left)
        right_max = self.maxDepth(root.right)

        # 利用max去最大深度，LeetCode用node計算depth，所以這邊要+1
        max_depth = 1 + max(left_max, right_max)

        return max_depth
