# class Solution:
#     def isPalindrome(self, s: str) -> bool:
#         # remove comma etc.
#         cleaned_s = "".join(char.lower() for char in s if char.isalnum())

#         # two pointer
#         left, right = 0, len(cleaned_s) - 1
#         while left < right:
#             if cleaned_s[left] == cleaned_s[right]:

#                 left += 1
#                 right -= 1
#             else:
#                 return False
        
#         return True

# # solution2 優化 sol1
# class Solution:
#     def isPalindrome(self, s: str) -> bool:
#         # remove comma etc.
#         cleaned_s = "".join(char.lower() for char in s if char.isalnum())

#         # two pointer
#         left, right = 0, len(cleaned_s) - 1
#         while left < right:
#             if cleaned_s[left] != cleaned_s[right]:
#                 return False
#             left += 1
#             right -= 1
        
#         return True

# solution3 先不將標點符號移除
class Solution:
    def isPalindrome(self, s: str) -> bool:
        left = 0
        right = len(s) - 1

        while left < right:

            # 跳過左邊的非英數字元
            if not s[left].isalnum():
                left += 1
                continue

            # 跳過右邊的非英數字元
            if not s[right].isalnum():
                right -= 1
                continue

            # 比較左右字元
            if s[left].lower() != s[right].lower():
                return False

            left += 1
            right -= 1

        return True


solution = Solution()
x = solution.isPalindrome(s="A man, a plan, a canal: Panama")
print(x)