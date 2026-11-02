# The isBadVersion API is already defined for you.
first_bad = 4
def isBadVersion(version: int) -> bool:
    return version >= first_bad

class Solution:
    def firstBadVersion(self, n: int) -> int:
        left = 1
        right = n

        while left < right:
            mid = (left + right) // 2

            if isBadVersion(mid):
                right = mid
            else:
                left = mid + 1

        return left

solution = Solution()
test1 = solution.firstBadVersion(n=5)
print(test1)