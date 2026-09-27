from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = defaultdict(list)

        for s in strs:
            count = [0]*26
            for c in s:
                num = ord(c) - 97
                count[num] +=1
            res[tuple(count)].append(s)
        return list(res.values())