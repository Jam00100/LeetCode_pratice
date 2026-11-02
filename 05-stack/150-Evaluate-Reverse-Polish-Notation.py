# class Solution:
#     def evalRPN(self, tokens: list[str]) -> int:
        
#         stack = []
#         for index in range(len(tokens)):
#             if tokens[index] == "+":
#                 val2 = stack.pop()
#                 val1 = stack.pop()
#                 stack.append(val1 + val2)

#             elif tokens[index] == "-":
#                 val2 = stack.pop()
#                 val1 = stack.pop()
#                 stack.append(val1 - val2)

#             elif tokens[index] == "*":
#                 val2 = stack.pop()
#                 val1 = stack.pop()
#                 stack.append(val1 * val2)

#             elif tokens[index] == "/":
#                 val2 = stack.pop()
#                 val1 = stack.pop()
#                 stack.append(int(val1 / val2))

#             else:
#                 stack.append(int(tokens[index]))
#         output = stack[0]
#         return output

class Solution:
    def evalRPN(self, tokens: list[str]) -> int:
        stack = []

        for token in tokens:

            if token in ("+", "-", "*", "/"):
                val2 = stack.pop()
                val1 = stack.pop()

                if token == "+":
                    result = val1 + val2

                elif token == "-":
                    result = val1 - val2

                elif token == "*":
                    result = val1 * val2

                else:
                    # 朝 0 截斷，避免浮點數誤差
                    quotient = abs(val1) // abs(val2)
                    result = -quotient if (val1 < 0) != (val2 < 0) else quotient

                stack.append(result)

            else:
                stack.append(int(token))

        return stack[-1]

sol = Solution()
output = sol.evalRPN(tokens=["4","13","5","/","+"])
print(output)