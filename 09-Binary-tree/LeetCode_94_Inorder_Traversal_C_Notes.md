# LeetCode 94 — Binary Tree Inorder Traversal（C 語言筆記）

## 整理自ChatGPT

## 1. 題目與走訪順序

給定 Binary Tree 的 `root`，按照 **Left → Root → Right** 的順序回傳所有節點數值。

```text
        1
       / \
      2   3
```

Inorder 結果：`[2, 1, 3]`

Python 可使用 `result.append(node.val)`；C 語言需要配置陣列並自行維護寫入索引。

## 2. 原本程式的問題

| 問題 | 原本寫法 | 修正原因 |
|---|---|---|
| 陣列容量固定 | `malloc(sizeof(int) * 2)` | 節點可能超過 2 個，造成越界寫入 |
| 巢狀函式 | 在 `inorderTraversal()` 裡定義 `inorder()` | 標準 C 不支援巢狀函式定義 |
| Helper 回傳型別 | `void* inorder(...)` | 不需要回傳值，應使用 `void` |
| 未設定結果長度 | 沒有修改 `*returnSize` | LeetCode 必須知道回傳陣列的長度 |
| 主函式未回傳 | 沒有 `return result;` | 題目要求回傳 `int*` |

## 3. 三個重要變數

| 變數 | 型別 | 傳遞方式 | 功能 |
|---|---|---|---|
| `result` | `int*` | `result` | 指向 `malloc()` 建立的結果陣列 |
| `index` | `int` | `&index` | 將索引的位址交給 Helper，讓遞迴共用同一個索引 |
| `returnSize` | `int*` | LeetCode 已傳入 | 透過 `*returnSize` 告知回傳陣列長度 |

### 3.1 為什麼 `result` 不用 `&`？

```c
int* result = malloc(sizeof(int) * 3);
inorder(root, result, &index);
```

`result` **本身就是指標**，存放陣列第一個元素的位址。將 `result` 傳入 Helper，雖然仍是 C 的「傳值」（複製位址），但兩個指標指向同一塊陣列記憶體，因此 Helper 可以透過 `result[i]` 修改內容。

```text
主函式 result ───┐
                 ├──> [ ? ][ ? ][ ? ]
Helper result ──┘
```

注意：修改陣列內容與修改指標變數本身是不同的事情。如果 Helper 要改變主函式的 `result` 指標指向哪裡，則需要額外的指標層級（例如 `int**`）。

### 3.2 為什麼 `index` 要傳入 `&index`？

若直接傳整數，函式只會修改自己的副本：

```c
void test(int index) {
    index++;
}

int main(void) {
    int index = 0;
    test(index);
    // index 仍為 0
}
```

傳入整數的**位址**，就能修改原本的變數：

```c
void test(int* index) {
    (*index)++;
}

int main(void) {
    int index = 0;
    test(&index);
    // index 現在是 1
}
```

| 語法 | 意義 |
|---|---|
| `index`（在主函式中，型別 `int`） | 整數值 |
| `&index`（在主函式中） | 取得整數變數的位址，型別 `int*` |
| `index`（在 Helper 中，型別 `int*`） | 指向原本整數的指標 |
| `*index`（在 Helper 中） | 讀取或修改該位址存放的整數 |
| `(*index)++` | 將原本的整數加 1 |
| `index++`（在 Helper 中） | 移動指標本身，**不是**增加原本的整數 |

### 3.3 為什麼遞迴呼叫不用再加 `&`？

第一次在主函式呼叫：

```c
int index = 0;
inorder(root, result, &index);
```

Helper 的參數已經是 `int* index`，因此在 Helper 內遞迴呼叫時直接傳 `index`：

```c
inorder(node->left, result, index);   // 正確：int*
// inorder(node->left, result, &index); // 錯誤：&index 是 int**
```

## 4. `result[*index]` 的執行方式

```c
result[*index] = node->val;
(*index)++;
```

1. `*index` 取得目前的寫入位置。
2. `result[*index]` 選擇陣列對應位置。
3. `node->val` 寫入目前節點的數值。
4. `(*index)++` 讓下一次寫入位置加 1。

假設樹是 `1` 的左右子節點分別為 `2`、`3`：

| 走訪節點 | 寫入動作 | 寫入後 `index` | 陣列已寫入內容 |
|---|---|---|---|
| 2 | `result[0] = 2` | 1 | `[2]` |
| 1 | `result[1] = 1` | 2 | `[2, 1]` |
| 3 | `result[2] = 3` | 3 | `[2, 1, 3]` |

## 5. `returnSize` 的用途

LeetCode 的 C 函式簽名：

```c
int* inorderTraversal(struct TreeNode* root, int* returnSize);
```

C 的 `int*` 不會自動攜帶陣列長度，因此要分別提供：

```c
*returnSize = count; // 結果有幾個元素
return result;       // 結果陣列的起始位址
```

## 6. 完整可提交的 C 程式碼

LeetCode 已提供 `struct TreeNode` 的定義。

```c
#include <stdlib.h>

// 計算 Tree 的節點數量
int countNodes(struct TreeNode* node) {
    if (node == NULL) {
        return 0;
    }

    return 1 + countNodes(node->left)
             + countNodes(node->right);
}

// Left -> Root -> Right
void inorder(struct TreeNode* node, int* result, int* index) {
    if (node == NULL) {
        return;
    }

    // Left
    inorder(node->left, result, index);

    // Root
    result[*index] = node->val;
    (*index)++;

    // Right
    inorder(node->right, result, index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    // Step 1：計算節點總數
    int count = countNodes(root);

    // Step 2：設定結果陣列長度
    *returnSize = count;

    // 空樹沒有元素
    if (count == 0) {
        return NULL;
    }

    // Step 3：配置足夠的記憶體
    int* result = malloc(sizeof(int) * count);
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // Step 4：建立寫入索引
    int index = 0;

    // Step 5：進行中序走訪
    inorder(root, result, &index);

    return result;
}
```

**記憶體管理：** `result` 是動態配置的陣列。提交到 LeetCode 時，測試環境會依題目介面處理回傳結果；如果在自己的 C 程式中呼叫，使用完結果後應由呼叫端 `free(result)`。

## 7. 複雜度

設 `n` 為節點數、`h` 為樹的高度：

| 項目 | 複雜度 | 原因 |
|---|---|---|
| 時間 | `O(n)` | `countNodes` 與 `inorder` 各走訪一次所有節點，`O(n) + O(n) = O(n)` |
| 結果陣列 | `O(n)` | 儲存所有節點值 |
| 遞迴堆疊 | `O(h)` | 最深呼叫層數取決於樹高 |
| 總空間 | `O(n)` | 結果陣列加上遞迴堆疊 |

## 8. 重點速記

- **Inorder = Left → Root → Right**。
- `result` 是 `int*`，直接傳入即可讓 Helper 寫入同一個陣列。
- `index` 是 `int`，第一次要傳 `&index` 才能讓 Helper 修改原本的整數。
- Helper 裡的 `index` 已經是 `int*`，後續遞迴直接傳 `index`。
- `result[*index] = node->val;` 負責寫入，`(*index)++;` 負責移動寫入位置。
- `*returnSize` 設定回傳長度，`return result` 回傳陣列位址。
- 標準 C 的 Helper Function 應定義在其他函式之外。
