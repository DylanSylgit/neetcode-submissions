from collections import defaultdict

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        dic = defaultdict(int)
        lis = [[] for _ in range(len(nums)+1)]

        for num in nums:
            dic[num] += 1

        for key in dic.keys():
            freq = dic[key]
            lis[freq].append(key)
        
        res = []
        for l in reversed(lis):
            if len(res) == k:
                return res
            if len(l) == 0:
                continue
            for num in l:
                res.append(num)
                if len(res) == k:
                    return res
            