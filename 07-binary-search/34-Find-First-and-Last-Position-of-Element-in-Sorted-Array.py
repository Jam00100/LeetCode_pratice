class Solution:
    def searchRange(self, nums: list[int], target: int) -> list[int]:

        # 找左邊界
        left = 0
        right = len(nums) - 1
        first = -1

        while left <= right:
            mid = left + (right - left) // 2

            if nums[mid] == target:
                first = mid
                right = mid - 1
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1

        # 找右邊界
        left = 0
        right = len(nums) - 1
        last = -1

        while left <= right:
            mid = left + (right - left) // 2

            if nums[mid] == target:
                last = mid
                left = mid + 1
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1

        return [first, last]


solution = Solution()
test1 = solution.searchRange(nums=[5,7,7,8,8,10], target=8)
print(test1)