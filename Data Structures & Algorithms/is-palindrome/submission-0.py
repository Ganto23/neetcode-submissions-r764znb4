class Solution:
    def isPalindrome(self, s: str) -> bool:

        s = s.lower()
        letter = "qwertyuiopasdfghjklzxcvbnm1234567890"

        new = ""
        for c in s:
            if c in letter:
                new += c
        

        if new[::-1] == new:
            return True
        else:
            return False 
        