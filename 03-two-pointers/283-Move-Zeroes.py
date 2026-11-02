# class Solution:
#     def moveZeroes(self, nums: list[int]) -> None:
#         """
#         Do not return anything, modify nums in-place instead.
#         """
#         zero = []
#         non_zero = []
#         for i in range(len(nums)):
#             if nums[i] == 0:
#                 zero.append(nums[i])
#             else:
#                 non_zero.append(nums[i])
#         nums[:] = non_zero+zero
#         return nums

# Solution2
class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        left = 0
        for right in range(len(nums)):
            if nums[right] != 0:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
        return nums

solution = Solution()
x = solution.moveZeroes(nums=[0,1,0,3,12])
print(x)