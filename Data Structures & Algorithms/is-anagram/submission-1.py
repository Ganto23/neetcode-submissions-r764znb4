class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        mappings = {}

        if len(s) != len(t):
            return False

        for l in s:
            if l not in mappings:
                mappings[l] = 1
            else:
                mappings[l] += 1
        
        for l in t:
            if l not in mappings:
                return False
            else:
                if mappings[l] == 0:
                    return False
                else:
                    mappings[l] -= 1

        return True
            