class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        check = {}
        result = bool
        for i in range(len(nums)):
             check[i] = nums[i]
             
        print(check)
        values = set(check.values())
        if len(check.values()) != len(values):
            result = True
        else:
            result = False
        return result


# solution 2
class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        values = set(nums)

        if len(nums) != len(values):
            return True
        else:
            return False

# soluion 3
class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        return len(nums) != len(set(nums))

solution = Solution()
x = solution.containsDuplicate(nums=[1,2,3,1])
print(x)