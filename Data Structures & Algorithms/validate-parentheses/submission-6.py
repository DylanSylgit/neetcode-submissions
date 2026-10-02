class Solution:
    def isValid(self, s: str) -> bool:
        parenthesis = {
            "{": "}", 
            "[" : "]",
            "(" : ")"
        }
        stack = []

        l = 0
        
        for char in s:
            if char in parenthesis.keys():
                stack.append(char)
            else:
                if not stack or parenthesis[stack.pop()] != char:
                    return False 
        return len(stack) == 0