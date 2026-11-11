# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def inorderTraversal(self, root: TreeNode | None) -> list[int]:
        
        # 紀錄經過的nodes
        result = []

        def inorder(node):

            # Step 1：Base Case
            if node is None:
                return

            # Step 2：遞迴左子樹
            inorder(node.left)

            # Step 3：記錄目前 Node 的數值
            result.append(node.val)

            # Step 4：遞迴右子樹
            inorder(node.right)

        inorder(root)

        return result