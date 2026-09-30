from collections import defaultdict

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not s or not t or len(s) < len(t):
            return ""
        
        t_dict = defaultdict(int)
        for c in t:
            t_dict[c] += 1

        local_dict = defaultdict(int)
        need = len(t_dict)
        have = 0

        best_len = 9999*9999
        best_window = (-1,-1)

        l = 0

        for r in range(len(s)):
            right = s[r]
            local_dict[right] += 1

            if local_dict[right] == t_dict[right]:
                have += 1
            
            while have == need:

                window_length = r - l + 1

                if window_length < best_len:
                    best_len = window_length
                    best_window = (l,r)
                
                left = s[l]
                local_dict[left] -= 1

                if left in t_dict and local_dict[left] < t_dict[left]:
                    have -= 1
                l += 1
        start, end = best_window
        return s[start:end+1] if best_len != 9999*9999 else ""