class Solution:
    def totalFruit(self, fruits: list[int]) -> int:
        left = 0
        count = {}
        max_length = 0

        # 1. 建立hash table
        for right in range(len(fruits)):
            current = fruits[right]
            count[current] = count.get(current, 0) + 1

        # 2. 檢查水果數量是否>2, > 2則開始刪除
            while len(count) > 2:
                left_fruit = count[current]
                print(left_fruit)

                left_fruit -= 1
                if left_fruit == 0:
                    del count[current]

                left += 1
            window_size = right - left + 1
            max_length = max(window_size , max_length)

        return max_length
    
solution = Solution()
x = solution.totalFruit(fruits=[1,2,1])
print(x)