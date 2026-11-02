# class Solution:
#     def removeDuplicates(self, s: str) -> str:
#         stack = []
#         for index in range(len(s)):
#             current = s[index]

#             if not stack:
#                 stack.append(current)
#             else:
#                 if stack[-1] == current:
#                     stack.pop()
#                 else:
#                     stack.append(current)

#         output = "".join(stack)
#         return output

class Solution:
    def removeDuplicates(self, s: str) -> str:
        stack = []

        for current in s:
            if stack and stack[-1] == current:
                stack.pop()
            else:
                stack.append(current)

        return "".join(stack)

solution = Solution()
x = solution.removeDuplicates(s="abbbabaaa")
print(x)