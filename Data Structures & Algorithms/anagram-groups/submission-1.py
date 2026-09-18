from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = {}

        for word in strs:
            dic = []
            for i in range(len(word)):
                dic.append(word[i])
            dick = tuple(sorted(dic))
            if dick in res:
                res[dick].append(word)
            else:
                res[dick] = [word]
        
        return list(res.values())