# 暴力解
# class Solution(object):
#     def containsNearbyDuplicate(self, nums, k):
#         """
#         :type nums: List[int]
#         :type k: int
#         :rtype: bool
#         """
#         for i in range(len(nums)):
#             for j in range(i + 1, min(i + k + 1, len(nums))):
#                 if nums[i] == nums[j]:
#                     return True

#         return False

# Hash
# class Solution(object):
#     def containsNearbyDuplicate(self, nums, k):
#         """
#         :type nums: List[int]
#         :type k: int
#         :rtype: bool
#         """
#         seen = {}
#         for i in range(len(nums)):
#             current = nums[i]

#             if current in seen:
#                 distance = abs(i - seen[current])

#                 if distance <= k:
#                     return True
#             seen[current] = i

#         return False

# Sliding window + Hash
class Solution:
    def containsNearbyDuplicate(self, nums: list[int], k: int) -> bool:
        window = set()

        for right in range(len(nums)):
            print(right)

            # Step 1：移除超出距離 k 的元素
            if right > k:
                window.remove(nums[right - k - 1])

            # Step 2：檢查目前數字是否已存在視窗中
            if nums[right] in window:
                return True

            # Step 3：將目前數字加入視窗
            window.add(nums[right])
            print(window)

        return False

solution = Solution()
x = solution.containsNearbyDuplicate(nums=[1,2,3,1,2,3], k=2)
print(x)