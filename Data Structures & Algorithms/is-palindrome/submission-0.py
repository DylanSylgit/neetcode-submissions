class Solution:
    def isPalindrome(self, s: str) -> bool:
        cleaned = "".join(char for char in s if char.isalnum())
        new = cleaned.lower().replace(" ","")

        for i in range(len(new)//2):
            if new[i] != new[len(new)-1-i]:
                return False

        return True