# class MinStack:

#     def __init__(self):
#         self.stack = []
#         self.min_stack = []

#     def push(self, value: int) -> None:
#         self.stack.append(value)

#         if not self.min_stack:
#             self.min_stack.append(value)
#         else:
#             current_min = min(value, self.min_stack[-1])
#             self.min_stack.append(current_min)

#     def pop(self) -> None:
#         self.stack.pop()
#         self.min_stack.pop()

#     def top(self) -> int:
#         return self.stack[-1]

#     def getMin(self) -> int:
#         return self.min_stack[-1]

# solution 2
class MinStack:

    def __init__(self):
        self.st = []

    def push(self, val: int) -> None:
        min_val = self.getMin()
        if min_val == None or min_val > val:
            min_val = val
        
        self.st.append([val, min_val])

    def pop(self) -> None:
        self.st.pop()

    def top(self) -> int:
        return self.st[-1][0] if self.st else None

    def getMin(self) -> int:
        return self.st[-1][1] if self.st else None


# Your MinStack object will be instantiated and called as such:
obj = MinStack()

obj.push(5)
obj.push(3)
obj.push(7)
obj.push(2)

obj.pop()
obj.pop()

print(obj.top())
print(obj.getMin())