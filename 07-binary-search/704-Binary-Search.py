class Solution:
    def search(self, nums: list[int], target: int) -> int:
        left = 0
        right = len(nums) - 1

        while left <= right:
            mid = (left + right) // 2

            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return -1


solution = Solution()
print(solution.search([-1, 0, 3, 5, 9, 12], 9))
# Expected: 4

# print(solution.search([-1, 0, 3, 5, 9, 12], 2))
# # Expected: -1

# print(solution.search([5], 5))
# # Expected: 0

# print(solution.search([5], -5))
# # Expected: -1

# print(solution.search([], 3))
# # Expected: -1