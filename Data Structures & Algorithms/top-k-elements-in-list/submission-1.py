from collections import defaultdict

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = defaultdict(int)
        # freq will store a list of numbers that appear i times
        # freq[i] = [numbers that appear i times]
        freq = [[] for i in range(len(nums)+1)]

        for n in nums:
            counts[n]+=1
        for n, c in counts.items():
            freq[c].append(n)
            
        res = []

        for i in range(len(freq)-1, -1,-1):
            for j in freq[i]:
                res.append(j)
                if len(res) == k:
                    return res
                

        

