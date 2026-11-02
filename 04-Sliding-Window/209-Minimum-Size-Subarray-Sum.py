# O(n squre)
# class Solution:
#     def minSubArrayLen(self, target: int, nums: list[int]) -> int:

#         # Window Size 從 1 開始，直到 len(nums)
#         for window_size in range(1, len(nums) + 1):

#             # 初始化第一個 Window
#             current_value = sum(nums[:window_size])

#             # 先檢查第一個 Window
#             if current_value >= target:
#                 return window_size

#             # Sliding Window
#             for index in range(window_size, len(nums)):

#                 current_value += nums[index]
#                 current_value -= nums[index - window_size]

#                 if current_value >= target:
#                     return window_size

#         return 0

# O(n)
class Solution:
    def minSubArrayLen(self, target: int, nums: list[int]) -> int:
        left = 0
        current_sum = 0
        min_length = float("inf")

        for right in range(len(nums)):
            # Step 1：擴大 Window
            current_sum += nums[right]

            # Step 2：當總和符合條件，嘗試縮小 Window
            while current_sum >= target:

                # 更新最短長度
                window_size = right - left + 1
                min_length = min(min_length, window_size)

                # 移除最左邊的元素
                current_sum -= nums[left]
                left += 1

        # 如果找不到符合條件的子陣列
        return 0 if min_length == float("inf") else min_length
    
solution = Solution()
x = solution.minSubArrayLen(target=15, nums=[1, 2, 3, 4, 5])
print(x)  # 5