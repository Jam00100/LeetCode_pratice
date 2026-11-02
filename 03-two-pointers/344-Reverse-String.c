
void reverseString(char* s, int sSize) {
    int left = 0;
    int right = sSize -1;

    while (left < right){
        // C 語言沒有 Python 的多重賦值交換語法，因此我們使用暫存變數 temp
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
}