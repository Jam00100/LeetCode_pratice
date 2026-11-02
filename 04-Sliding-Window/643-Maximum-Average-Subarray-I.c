#include <stdio.h>
#include <stdlib.h>

int sum(int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

double findMaxAverage(int* nums, int numsSize, int k) {
    int window_sum = sum(nums, k);
    int best_score = window_sum;

    for (int right=k; right < numsSize; right ++){
        // int temp = window_sum + nums[right];
        // window_sum = temp - nums[right-k];
        
        // or
        window_sum += nums[right];
        window_sum -= nums[right - k];

        if (window_sum > best_score){
            best_score = window_sum;
        }
    }
    float n = (float)k;
    return (double) best_score / n;
}

int main() {
    // 3. C 語言必須先宣告陣列變數，不能直接在參數寫 [1, 12, ...]
    int nums[] = {1, 12, -5, -6, 50, 3}; 
    
    // 呼叫函式並將結果指派給 float (或 double)
    float x = findMaxAverage(nums, 6, 4);
    
    printf("最大平均值為: %f\n", x); // 輸出結果：12.750000
    
    return 0;
}