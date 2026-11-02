class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        pairs = {
            ')': '(',
            ']': '[',
            '}': '{'
        }

        for char in s:
            # Step 1:
            # 如果 char 是左括號
            # 將 char 加入 stack
            if char in pairs.values():
                stack.append(char)
            # Step 2:
            # 如果 char 是右括號
            elif char in pairs:
            # 檢查 stack 是否為空
                if not stack:
                    return False
            # 檢查 stack[-1] 是否符合 pairs[char]
                if stack[-1] == pairs[char]:
                    stack.pop()
                else:
                    return False
            # 正確就 pop，錯誤就 return False

        # Step 3:
        # 確認 stack 是否為空
        # 回傳 True 或 False
        if not stack:
            return True
        else:
            return False

solution = Solution()
x = solution.isValid(s="([])")
print(x)