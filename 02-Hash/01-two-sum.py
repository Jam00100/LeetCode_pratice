#解法1
class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        for i in range(len(nums)):
            for j in range(len(nums)):
                if nums[i] + nums[j] == target and i != j:
                    print(nums[i], nums[j])
                    return [i, j]

#解法二利用Ｈash
class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        seen = {}

        for i in range(len(nums)):
            current = nums[i]
            need = target - current

            if need in seen:
                return [seen[need], i]

            seen[current] = i


solution = Solution()
x = solution.twoSum(nums=[2, 7, 11, 15], target=9)
print(x)