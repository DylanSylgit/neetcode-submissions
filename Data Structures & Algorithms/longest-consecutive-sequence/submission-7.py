class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        ls = set(nums)
        streak = 0
        ret = 0

        for num in ls:
            i = num
            if i-1 not in ls: #start streak
                streak+=1
                ret = max(ret,streak)
                i += 1
                while i in ls:
                    streak+=1
                    ret = max(ret,streak)
                    i +=1
            streak = 0
        return ret