
def runningSum(nums: list[int]) -> list[int]:
	output = []
	sums = 0
	for i in range(len(nums)):
		sums = nums[i] + sums
		output.append(sums)
	return output

x = runningSum()