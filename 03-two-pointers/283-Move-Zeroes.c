
void moveZeroes(int* nums, int numsSize) {
    int left = 0;

    for (int right = 0; right < numsSize; right++) {
        if (nums[right] != 0) {
            int temp = nums[right];
            nums[right] = nums[left];
            nums[left] = temp;

            left++;
        }
    }
}