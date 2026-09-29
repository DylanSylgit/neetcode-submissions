from collections import defaultdict

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        string1 = defaultdict(int)
        local = defaultdict(int)
        for c in s1:
            string1[c] += 1
        
        k = len(s1)
        l = 0
        r = 0
        while r < len(s2):
            left = s2[l]
            right = s2[r]
            window_length = r - l + 1
            if right not in string1:
                r+=1
                l = r
                local.clear()
                continue
            local[right] += 1
            if window_length == k:
                if local == string1:
                    return True
                else:
                    local[left] -= 1
                    l+=1
            r += 1
        return False
            