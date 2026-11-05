
# Binary Tree（二元樹）基礎筆記

## 1. Binary Tree 的基本結構

Binary Tree（二元樹）是一種階層式資料結構，每個節點（Node）最多只能有兩個子節點：

- Left Child：左子節點
- Right Child：右子節點

例如：

```text
        1
       / \
      2   3
     / \
    4   5
```

基本名詞：

- Root：根節點，例如 `1`
- Parent：父節點，例如 `2` 是 `4` 的父節點
- Child：子節點，例如 `4`、`5` 是 `2` 的子節點
- Leaf：沒有子節點的節點，例如 `3`、`4`、`5`
- Subtree：以某個節點為根的子樹

**注意：** Binary Tree 不一定有大小排序規則。左邊較小、右邊較大是 Binary Search Tree（BST）的特性。

---

## 2. Python 與 C 語言的節點表示方式

### Python

```python
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
```

### C

```c
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
```

### 語法對照

| 功能 | Python | C |
|---|---|---|
| 取得節點數值 | `root.val` | `root->val` |
| 取得左子節點 | `root.left` | `root->left` |
| 取得右子節點 | `root.right` | `root->right` |
| 判斷空節點 | `root is None` | `root == NULL` |
| 取得左子節點的數值 | `root.left.val` | `root->left->val` |

**注意：** 存取子節點的屬性前，應先確認該子節點不是 `None` 或 `NULL`。

---

## 3. DFS（Depth-First Search）

DFS（深度優先搜尋）會沿著一條分支深入探索，再返回上一層探索其他分支。

Binary Tree 常見的三種 DFS Traversal：

| 遍歷方式 | 順序 | 範例結果 |
|---|---|---|
| Preorder（前序） | Root → Left → Right | `[1,2,4,5,3]` |
| Inorder（中序） | Left → Root → Right | `[4,2,5,1,3]` |
| Postorder（後序） | Left → Right → Root | `[4,5,2,3,1]` |

### Python 範例

```python
# Preorder
def preorder(root):
    if root is None:
        return

    print(root.val)
    preorder(root.left)
    preorder(root.right)


# Inorder
def inorder(root):
    if root is None:
        return

    inorder(root.left)
    print(root.val)
    inorder(root.right)


# Postorder
def postorder(root):
    if root is None:
        return

    postorder(root.left)
    postorder(root.right)
    print(root.val)
```

**記憶方式：** 觀察 `print(root.val)` 的位置。

- 遞迴之前：Preorder
- 兩次遞迴之間：Inorder
- 遞迴之後：Postorder

---

## 4. BFS（Breadth-First Search）

BFS（廣度優先搜尋）會按照層級遍歷節點，通常使用 Queue（佇列）。

Queue 採用 FIFO（First In, First Out），先進先出。

例如：

```text
        1         Level 1
       / \
      2   3       Level 2
     / \
    4   5         Level 3
```

BFS 遍歷結果：

```text
[1, 2, 3, 4, 5]
```

Python 通常使用：

```python
from collections import deque
```

### DFS 與 BFS 比較

| 項目 | DFS | BFS |
|---|---|---|
| 搜尋方式 | 優先往深處探索 | 優先探索同一層 |
| 常見資料結構 | Recursion / Stack | Queue |
| 常見用途 | 樹的深度、路徑、子樹問題 | 層序遍歷、最短路徑（無權圖） |

---

## 5. Binary Tree 與 Recursion

Binary Tree 很適合使用 Recursion，因為每個子樹本身也是一棵 Binary Tree。

基本遞迴流程：

1. Base Case：遇到空節點時停止。
2. Recursive Case：遞迴處理左子樹。
3. Recursive Case：遞迴處理右子樹。
4. Combine：合併左右子樹的結果。

### Recursion 的 Base Case

Python：

```python
if root is None:
    return 0
```

C：

```c
if (root == NULL) {
    return 0;
}
```

---

## 重點總結

1. Binary Tree 每個節點最多有兩個子節點。
2. Python 使用 `root.left` / `root.right`，C 使用 `root->left` / `root->right`。
3. DFS 包含 Preorder、Inorder、Postorder，通常使用 Recursion 或 Stack。
4. BFS 按照層級遍歷，通常使用 Queue。
5. Binary Tree 的 Recursion 通常以空節點作為 Base Case，再處理左右子樹。
