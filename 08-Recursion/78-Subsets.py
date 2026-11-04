class Solution:
    def subsets(self, nums: list[int]) -> list[list[int]]:
        # 紀錄result, Path
        result = []
        path = []

        def backtrack(start):
            # 記錄目前的子集合
            result.append(path.copy())

            for i in range(start, len(nums)):
                # Step 1：Choose
                path.append(nums[i])

                # Step 2：Explore
                backtrack(i + 1)

                # Step 3：Unchoose
                path.pop()

        backtrack(0)

        return result


solution = Solution()
test1 = solution.subsets(nums=[1, 2])
print(test1)