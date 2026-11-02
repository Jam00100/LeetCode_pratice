#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int minSubArrayLen(int target, int* nums, int numsSize) {
    int left = 0;
    int current_sum = 0;
    int min_length = INT_MAX;

    for (int right = 0; right < numsSize; right++) {

        // 擴大 Window
        current_sum += nums[right];

        // 縮小 Window
        while (current_sum >= target) {

            int window_size = right - left + 1;

            min_length = min(min_length, window_size);

            current_sum -= nums[left];
            left++;
        }
    }

    if (min_length == INT_MAX) {
        return 0;
    }

    return min_length;
}