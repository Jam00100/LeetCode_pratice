class Solution:
    def searchInsert(self, nums: list[int], target: int) -> int:
        left = 0
        right = len(nums) - 1

        while left <= right:
            mid = (left + right) // 2

            if nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid - 1
            else:
                return mid
            print(left)
        return left
        # if nums[mid] > target:
        #     return mid
        # else:
        #     return mid + 1


solution = Solution()
test1 = solution.searchInsert(nums=[1,3,5,6], target=7)
print(test1)