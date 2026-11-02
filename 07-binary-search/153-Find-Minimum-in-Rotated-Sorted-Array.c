#include <stdio.h>
#include <stdlib.h>

int findMin(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;

    while (left < right){
        int mid = left + (right - left) / 2;

        if (nums[mid] < nums[right]){
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return nums[left];
}

//while left <= right：允許搜尋最後一個元素，通常搭配 mid + 1、mid - 1，直到找到答案或搜尋範圍變空。
//while left < right：當左右指標相遇就停止，通常用於尋找邊界或極值，並保留可能是答案的 mid。