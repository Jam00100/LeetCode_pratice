class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1.0

        # 負指數：先計算正指數，再取倒數
        if n < 0:
            return 1 / self.myPow(x, -n)

        half = self.myPow(x, n // 2)

        if n % 2 == 0:
            return half * half
        else:
            return half * half * x

solution = Solution()
test1 = solution.myPow(x=2, n=-3)
print(test1)