class Solution:
    def reverseString(self, s: list[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        def helper(left, right):
            if left >= right:
                return

            s[left], s[right] = s[right], s[left]

            helper(left + 1, right - 1)

        helper(0, len(s) - 1)


solution = Solution()
s = ["h", "e", "l", "l", "o"]
solution.reverseString(s)
print(s)
# ['o', 'l', 'l', 'e', 'h']