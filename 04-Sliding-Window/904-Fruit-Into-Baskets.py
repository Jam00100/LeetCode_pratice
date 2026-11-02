class Solution:
    def totalFruit(self, fruits: list[int]) -> int:
        left = 0
        count = {}
        max_length = 0

        for right in range(len(fruits)):

            # Step 1：加入目前水果
            current = fruits[right]
            count[current] = count.get(current, 0) + 1

            # Step 2：超過兩種水果，縮小 Window
            while len(count) > 2:
                left_fruits = fruits[left]

                # 移除視窗最左邊的一個水果
                count[left_fruits] -= 1

                # 如果數量變成 0，刪除這個 Key
                if count[left_fruits] == 0:
                    del count[current]

                # 移動左指標
                left += 1

            # Step 3：更新最長長度
            window_size = right - left + 1
            max_length = max(window_size, max_length)

        return max_length
    
solution = Solution()
x = solution.totalFruit(fruits=[1,2,1])
print(x)