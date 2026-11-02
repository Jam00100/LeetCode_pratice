# solution 1
class Solution:
    def shuffle(self, nums: list[int], n: int) -> list[int]:
        output = []
        for i in range(n):
            x1 = nums[i]
            y1 = nums[i+n]
            output.append(x1)
            output.append(y1)
        return output 

def shuffle(nums: list[int], n: int) -> list[int]:
    output = []

    for i in range(2 * n):

        if i % 2 == 0:
            print(i)
            new_idx = i // 2
            output.append(nums[new_idx])

        else:
            new_idx = n + i //2
            output.append(nums[new_idx])

    return output

x = shuffle(nums=[2, 5, 1, 3, 4, 7], n=3)
print(x)