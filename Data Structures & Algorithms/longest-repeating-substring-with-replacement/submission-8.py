from collections import defaultdict
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        res = 0
        l = 0
        max_freq = 0
        freq = defaultdict(int)
        r = l

        while r < len(s):
            window_length = r - l + 1
            freq[s[r]] += 1
            max_freq = max(max_freq,freq[s[r]])
            replacement = window_length - max_freq
            if replacement <= k:
                res = max(res,window_length)
            else:
                freq[s[l]] -= 1
                l += 1
            r += 1
        return res