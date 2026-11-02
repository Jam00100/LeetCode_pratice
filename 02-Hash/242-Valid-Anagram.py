# solution 1
# class Solution:
# 	def isAnagram(self, s: str, t: str) -> bool:
# 		if len(s) != len(t):
# 			return False
		
# 		word1, word2 = {}, {}
# 		for i in s:
# 			if i not in word1:
# 				word1[i] = 1
# 			else:
# 				word1[i] += 1
# 		for i in t:
# 			if i not in word2:
# 				word2[i] = 1
# 			else:
# 				word2[i] += 1

# 		if word1.keys() == word2.keys():
# 			count = 0
# 			for i in word1.keys():
# 				if word1[i] == word2[i]:
# 					count += 1
# 				else:
# 					return False
# 			if count == len(word1.keys()) and count == len(word2.keys()):

# 				return True
# 		else:
# 			return False

# # Solution 2
# class Solution:
#     def isAnagram(self, s: str, t: str) -> bool:
#         if len(s) != len(t):
#             return False

#         word1, word2 = {}, {}
#         for char in s:
#             if char not in word1:
#                 word1[char] = 1
#             else:
#                 word1[char] += 1

#         for char in t:
#             if char not in word2:
#                 word2[char] = 1
#             else:
#                 word2[char] += 1

#         return word1 == word2

# # 
# class Solution:
#     def isAnagram(self, s: str, t: str) -> bool:
#         if len(s) != len(t):
#             return False

#         word1, word2 = {}, {}

#         for char in s:
#             word1[char] = word1.get(char, 0) + 1

#         for char in t:
#             word2[char] = word2.get(char, 0) + 1

#         return word1 == word2


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        count = {}
        for char in s:
            count[char] = count.get(char, 0) + 1

        for char in t:
            count[char] = count.get(char, 0) - 1

        return all(value == 0 for value in count.values())

solution = Solution()
x = solution.isAnagram("apple", "ppale")
print(x)