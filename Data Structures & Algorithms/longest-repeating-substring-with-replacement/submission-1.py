class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        left = 0
        res = 0
        letters = dict()
        maxFreq = 0

        for right in range(len(s)):
            if s[right] in letters:
                letters[s[right]] += 1
            else:
                letters[s[right]] = 1

            maxFreq = max(maxFreq, letters[s[right]])

            size = (right - left + 1)
            replacements = size - maxFreq

            if replacements > k:
                letters[s[left]] -= 1
                left+=1
            else:
                res = max(res,size)
        return res