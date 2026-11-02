# solution 1 Hash
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        ### 
        if len(ransomNote) > len(magazine):
            return False
        ### 先計算ransomNote字元出現次數
        ### 在ransomNote中出現+1, 在Magazine出現-1
        count = {}
        for char in ransomNote:
            count[char] = count.get(char, 0) + 1
        for char in magazine:
            count[char] = count.get(char, 0) - 1

        # 檢查count中是否有多餘的char無法被消除
        # for char in ransomNote:
        #     if count[char] > 0:
        #         return False
        for value in count.values():
            if value > 0:
                return False

        return True

# solution 2 Frequency array
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        if len(ransomNote) > len(magazine):
            return False

        #建立字母總長度的array
        count = [0] * 26

        for char in magazine:
            # 將char轉換成uni code
            count[ord(char) - ord('a')] += 1

        for char in ransomNote:
            # 獲得ransomNote char在count中的index
            index = ord(char) - ord('a')
            count[index] -= 1

            if count[index] < 0:
                return False

        return True