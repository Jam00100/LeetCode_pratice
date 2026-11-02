class Solution:
    def fib(self, n: int) -> int:
        # Base Case
        if n == 0:
            return 0

        if n == 1:
            return 1
        
        # Recursive Case
        return self.fib(n-1) + self.fib(n-2)

class Solution:
    def fib(self, n: int) -> int:
        print(f"進入 fib({n})")

        if n == 0:
            print("fib(0) 回傳 0")
            return 0

        if n == 1:
            print("fib(1) 回傳 1")
            return 1

        a = self.fib(n - 1)
        b = self.fib(n - 2)

        result = a + b
        print(f"fib({n}) = {a} + {b} = {result}")

        return result


solution = Solution()
print("最終結果：", solution.fib(3))

# solution = Solution()
# test1 = solution.fib(n=4)
# print(test1)