# soultion 1 Hash
# class Solution:
#     def twoSum(self, numbers: list[int], target: int) -> list[int]:
#         output = []
#         seen = {}

#         for i in range(len(numbers)):
#             current = numbers[i]
#             need = target - current
#             if need in seen:
#                 return [seen[need], i]

#             seen[current] = i

# soultion 2 two pointers
class Solution:
    def twoSum(self, numbers: list[int], target: int) -> list[int]:
        left, right = 0, len(numbers) - 1

        while left < right:
            current_sum = numbers[left] + numbers[right]
            print(current_sum)
            if current_sum == target:
                return [left + 1, right +1]
            elif current_sum < target:
                left += 1
            else:
                right -= 1

solution = Solution()
x = solution.twoSum(numbers=[2,7,11,15], target=9)
print(x)