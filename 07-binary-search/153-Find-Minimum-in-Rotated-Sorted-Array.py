class Solution:
    def findMin(self, nums: list[int]) -> int:
        left = 0
        right = len(nums) - 1

        while left < right:
            mid = left + (right - left) // 2

            if nums[mid] > nums[right]:
                left = mid + 1
            else:
                right = mid

        return nums[left]

solution = Solution()

test_cases = [
    ([3, 4, 5, 1, 2], 1),
    ([4, 5, 6, 7, 0, 1, 2], 0),
    ([11, 13, 15, 17], 11),
    ([2, 1], 1),
    ([1], 1),
    ([2, 3, 4, 5, 1], 1),
]

for nums, expected in test_cases:
    result = solution.findMin(nums)
    print(f"nums={nums}, result={result}, expected={expected}")
    assert result == expected

print("All tests passed!")