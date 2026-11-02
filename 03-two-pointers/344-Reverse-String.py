# solution 1
# class Solution:
#     def reverseString(self, s: list[str]) -> None:
#         """
#         Do not return anything, modify s in-place instead.
#         Input:  ['h', 'e', 'l', 'l', 'o']
#         Output: ['o', 'l', 'l', 'e', 'h']
#         """
#         # left to right index start
#         left = 0
#         # right to left index start
#         right = -1
#         output = []
#         for i in range(len(s)):
#             char_index = right - i
#             output.append(s[char_index])

#         s[:] = output
#         return s

# solution 2 two pointer
class Solution:
    def reverseString(self, s: list[str]) -> None:
        left = 0
        right = len(s) - 1

        while left < right:
            s[left], s[right] = s[right], s[left]

            left += 1
            right -= 1

solution = Solution()
x = solution.reverseString(s = ["h","e","l","l","o"])
print(x)