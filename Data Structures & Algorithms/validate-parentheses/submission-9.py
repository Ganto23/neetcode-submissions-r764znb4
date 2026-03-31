class Solution:
    def isValid(self, s: str) -> bool:
        mappings = {'(':')','[':']','{':'}',')':'(',']':'[','}':'{'}
        stack = []
        length = -1

        if s[0] in [')',']','}']:
            return False

        for c in s:
            print(stack)
            if length ==-1:
                stack.append(c)
                length += 1
            elif c in ['(', '[', '{']:
                stack.append(c)
                length += 1
            elif mappings[c] != stack[length]:
                print(c, stack[length])
                return False
                stack.append(c)
                length += 1 
            else:
                stack.pop()
                length -= 1

        if stack == []:
            return True 
        else:
            return False
        