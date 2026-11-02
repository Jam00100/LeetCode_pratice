class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left = 0
        seen = set()
        max_length = 0

        for right in range(len(s)):
            while s[right] in seen:
                seen.remove(s[left])
                left += 1

            seen.add(s[right])

            window_size = right - left + 1
            max_length = max(max_length, window_size)

        return max_length

    
solution = Solution()
x = solution.lengthOfLongestSubstring(s="pwwkew")
print(x)