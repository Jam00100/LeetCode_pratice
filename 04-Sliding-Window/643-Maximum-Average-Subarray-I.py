class Solution(object):
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        window_sum = sum(nums[:k])
        best_score = window_sum

        for right in range(k, len(nums)):
            window_sum += nums[right]
            window_sum -= nums[right-k]

            if window_sum > best_score:
                best_score = window_sum

        return best_score / float(k)

solution = Solution()
x = solution.findMaxAverage(nums=[1,12,-5,-6,50,3], k=4)
print(x)