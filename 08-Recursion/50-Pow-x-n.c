double myPow(double x, int n) {
    // Base Case
    if (n == 0) {
        return 1.0;
    }

    // 處理負指數
    if (n < 0) {
        // 避免 INT_MIN 取負造成 overflow
        return 1.0 / (x * myPow(x, -(n + 1)));
    }

    // Recursive Case
    double half = myPow(x, n / 2);

    // 偶數
    if (n % 2 == 0) {
        return half * half;
    }
    // 奇數
    else {
        return half * half * x;
    }
}